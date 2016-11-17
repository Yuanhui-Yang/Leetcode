// 373. Find K Pairs with Smallest Sums
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/50481/clean-16ms-c-o-n-space-o-klogn-time-solution-using-priority-queue
// BEGIN: https://discuss.leetcode.com/topic/50421/c-priority_queue-solution
// BEGIN: http://stackoverflow.com/questions/3810519/how-to-use-a-lambda-expression-as-a-template-parameter
class Solution {
public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<pair<int, int>> result;
		if (nums1.empty() || nums2.empty() || k <= 0) return result;
		priority_queue<pair<int, int>, vector<pair<int, int>>, comp> max_heap;
		for (const auto &i : nums1) {
			for (const auto &j : nums2) {
				if (max_heap.size() < k) {
					max_heap.push(make_pair(i, j));
					continue;
				}
				if (i + j < max_heap.top().first + max_heap.top().second) {
					max_heap.pop();
					max_heap.push(make_pair(i, j));
				}
			}
		}
		while (!max_heap.empty()) {
			result.push_back(max_heap.top());
			max_heap.pop();
		}
		return result;
	}
private:
	struct comp {
		bool operator() (pair<int, int>& a, pair<int, int>& b) {
			return a.first + a.second < b.first + b.second;
		}
	};
};
// class Solution {
// public:
// 	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
// 		vector<pair<int, int>> result;
// 		if (nums1.empty() || nums2.empty() || k <= 0) return result;
// 		auto comp = [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
// 			return a.first + a.second < b.first + b.second;
// 		};
// 		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> max_heap(comp);
// 		for (const auto &i : nums1) {
// 			for (const auto &j : nums2) {
// 				if (max_heap.size() < k) {
// 					max_heap.push(make_pair(i, j));
// 					continue;
// 				}
// 				if (i + j < max_heap.top().first + max_heap.top().second) {
// 					max_heap.pop();
// 					max_heap.push(make_pair(i, j));
// 				}
// 			}
// 		}
// 		while (!max_heap.empty()) {
// 			result.push_back(max_heap.top());
// 			max_heap.pop();
// 		}
// 		return result;
// 	}
// };
// END: http://stackoverflow.com/questions/3810519/how-to-use-a-lambda-expression-as-a-template-parameter
// END: https://discuss.leetcode.com/topic/50421/c-priority_queue-solution
// END: https://discuss.leetcode.com/topic/50481/clean-16ms-c-o-n-space-o-klogn-time-solution-using-priority-queue
int main(void) {
	Solution solution;
	vector<int> nums1, nums2;
	for (const auto&i : solution.kSmallestPairs(nums1, nums2, 0)) cout << i.first << ',' << i.second << '\t';
	cout << "\tPassed\n";
	nums1 = {1,7,11};
	nums2 = {2,4,6};
	for (const auto&i : solution.kSmallestPairs(nums1, nums2, 3)) cout << i.first << ',' << i.second << '\t';
	cout << "\tPassed\n";
	nums1 = {1,1,2};
	nums2 = {1,2,3};
	for (const auto&i : solution.kSmallestPairs(nums1, nums2, 2)) cout << i.first << ',' << i.second << '\t';
	cout << "\tPassed\n";
	nums1 = {1,2};
	nums2 = {3};
	for (const auto&i : solution.kSmallestPairs(nums1, nums2, 3)) cout << i.first << ',' << i.second << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}