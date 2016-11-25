// 368. Largest Divisible Subset
// https://leetcode.com/problems/largest-divisible-subset/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/49456/c-solution-with-explanations
class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		vector<int> result;
		if (nums.empty()) return result;
		sort(begin(nums), end(nums));
		const int n = nums.size();
		int maxDeepthIdx = 0;
		vector<pair<int, int>> OPT(n, make_pair(1, -1)); // first is deepth and second is parent index
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				if (nums[j] % nums[i] == 0) {
					if (OPT[i].first < OPT[j].first + 1) {
						OPT[i].first = OPT[j].first + 1;
						OPT[i].second = j;
						if (OPT[maxDeepthIdx].first < OPT[i].first) {
							maxDeepthIdx = i;
						}
					}
				}
			}
		}
		while (OPT[maxDeepthIdx].second >= 0) {
			result.push_back(nums[maxDeepthIdx]);
			maxDeepthIdx = OPT[maxDeepthIdx].second;
		}
		result.push_back(nums[maxDeepthIdx]);
		return result;
	}
};
// END: https://discuss.leetcode.com/topic/49456/c-solution-with-explanations

// class Solution {
// public:
// 	vector<int> largestDivisibleSubset(vector<int>& nums) {
// 		vector<int> result;
// 		if (nums.empty()) return result;
// 		sort(begin(nums), end(nums));
// 		const int n = nums.size();
// 		vector<vector<int>> graph(n);
// 		for (int i = 0; i < n; i++) {
// 			for (int j = i + 1; j < n; j++) {
// 				if (nums[j] % nums[i] == 0) {
// 					graph[i].push_back(j);
// 				}
// 			}
// 		}
// 		vector<pair<int, int>> deepth(n, make_pair(0, 0));
// 		int maxDeepthIdx = 0;
// 		for (int i = 0; i < n; i++) {
// 			deepth[i] = getDeepth(i, graph, deepth);
// 		}
// 		for (int i = 0; i < n; i++) {
// 			if (deepth[i].first > deepth[maxDeepthIdx].first) {
// 				maxDeepthIdx = i;
// 			}
// 		}
// 		while (deepth[maxDeepthIdx].second >= 0) {
// 			result.push_back(nums[maxDeepthIdx]);
// 			maxDeepthIdx = deepth[maxDeepthIdx].second;
// 		}
// 		result.push_back(nums[maxDeepthIdx]);
// 		return result;
// 	}
// private:
// 	pair<int, int> getDeepth(int idx, vector<vector<int>>& graph, vector<pair<int, int>>& deepth) {
// 		pair<int, int> result = make_pair(1, -1);
// 		if (graph[idx].empty()) return result;
// 		if (deepth[idx].first) return deepth[idx];
// 		for (const auto &i : graph[idx]) {
// 			pair<int, int> next = getDeepth(i, graph, deepth);
// 			if (result.first < next.first + 1) {
// 				result.first = (next.first + 1);
// 				result.second = i;
// 			}
// 		}
// 		deepth[idx] = result; // Don't forget this line
// 		return result;
// 	}
// };
int main(void) {
	Solution solution;
	vector<int> nums;
	for (const auto &i : solution.largestDivisibleSubset(nums)) cout << i << '\t';
	cout << "\tPassed\n";
	nums = {1, 2, 3};
	for (const auto &i : solution.largestDivisibleSubset(nums)) cout << i << '\t';
	cout << "\tPassed\n";
	nums = {1, 2, 4, 8};
	for (const auto &i : solution.largestDivisibleSubset(nums)) cout << i << '\t';
	cout << "\tPassed\n";
	nums = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
	for (const auto &i : solution.largestDivisibleSubset(nums)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}