// 325. Maximum Size Subarray Sum Equals k
// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/

/*
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxSubArrayLen(vector<int>& nums, int k) {
		unordered_map<int, int> h;
		h[0] = -1;
		int result = 0;
		for (int n = nums.size(), sum = 0, i = 0; i < n; ++i) {
			sum += nums[i];
			if (h.count(sum - k)) {
				result = max(result, i - h[sum - k]);
			}
			if (!h.count(sum)) {
				h[sum] = i;
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	int k, answer, result;

	nums = {1, -1, 5, -2, 3};
	k = 3;
	answer = 4;
	result = solution.maxSubArrayLen(nums, k);
	assert(answer == result);

	nums = {-2, -1, 2, 1};
	k = 1;
	answer = 2;
	result = solution.maxSubArrayLen(nums, k);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}