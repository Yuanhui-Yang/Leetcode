// 213. House Robber II
// https://leetcode.com/problems/house-robber-ii/

/*
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		if (nums.size() == 1) {
			return nums.front();
		}
		return max(f(begin(nums), prev(end(nums))), f(next(begin(nums)), end(nums)));
	}
private:
	int f(vector<int>::iterator begin, vector<int>::iterator end) {
		int result = 0, prev = 0;
		for (; begin < end; ++begin) {
			int t = result;
			result = max(result, prev + *begin);
			prev = t;
		}
		return result;
	}
};