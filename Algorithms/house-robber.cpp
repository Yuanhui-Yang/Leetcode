// 198. House Robber
// https://leetcode.com/problems/house-robber/

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) {
			return 0;
		}
		if (n == 1) {
			return nums[0];
		}
		if (n == 2) {
			return max(nums[0], nums[1]);
		}
		int result = nums[0];
		nums[1] = max(nums[0], nums[1]);
		result = max(result, nums[1]);
		for (int i = 2; i < n; ++i) {
			int val = nums[0];
			for (int j = 1; j <= i - 2; ++j) {
				if (val < nums[j]) {
					val = nums[j];
				}
			}
			nums[i] += val;
			result = max(result, nums[i]);
		}
		return result;
	}
};