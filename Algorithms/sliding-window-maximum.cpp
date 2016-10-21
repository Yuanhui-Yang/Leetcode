// 239. Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/
#include <iostream>
#include <vector>
#include <climits>
#include <deque>
#include <algorithm>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/19055/java-o-n-solution-using-deque-with-explanation
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> result;
		deque<int> dq;
		const int n = nums.size();
		for (int i = 0; i < n; i++) {
			while (!dq.empty() && i - dq.front() > k - 1) dq.pop_front();
			while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
			dq.push_back(i);
			if (i >= k - 1) result.push_back(nums[dq.front()]);
		}
		return result;
	}
};
// END: https://discuss.leetcode.com/topic/19055/java-o-n-solution-using-deque-with-explanation
// class Solution {
// public:
// 	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
// 		vector<int> result;
// 		const int n = nums.size();
// 		if (n == 0) return result;
// 		deque<int> dq;
// 		int maxVal = INT_MIN;
// 		for (int i = 0; i < n; i++) {
// 			maxVal = INT_MIN;
// 			if ((int)dq.size() + 1 < k) {
// 				dq.push_back(nums[i]);
// 				maxVal = max(maxVal, nums[i]);
// 				continue;
// 			}
// 			dq.push_back(nums[i]);
// 			for (const auto &j : dq) maxVal = max(maxVal, j);
// 			result.push_back(maxVal);
// 			dq.pop_front();
// 		}
// 		if (n < k) result.push_back(maxVal);
// 		return result;
// 	}
// };
int main(void) {
	Solution solution;
	vector<int> nums;
	for (const auto &i : solution.maxSlidingWindow(nums, 0)) cout << i << '\t';
	cout << "\tPassed\n";
	nums = {1,3,-1,-3,5,3,6,7};
	for (const auto &i : solution.maxSlidingWindow(nums, 3)) cout << i << '\t';
	cout << "\tPassed\n";
	nums = {1,-1};
	for (const auto &i : solution.maxSlidingWindow(nums, 1)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}