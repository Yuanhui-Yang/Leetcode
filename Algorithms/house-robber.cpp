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
		int result = nums[0], prev = nums[0];
		nums[1] = max(nums[0], nums[1]);
		result = max(result, nums[1]);
		for (int i = 2; i < n; ++i) {
			nums[i] = max(nums[i - 1], max(prev, 0) + nums[i]);
			prev = max(prev, nums[i - 1]);
			result = max(result, nums[i]);
		}
		return result;
	}
};

class Solution {
public:
	int rob(vector<int>& nums) {
		int result = 0, prev = 0;
		for (const auto & i : nums) {
			int t = result;
			result = max(result, prev + i);
			prev = t;
		}
		return result;
	}
};