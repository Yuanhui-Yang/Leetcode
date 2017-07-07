// 137. Single Number II
// https://leetcode.com/problems/single-number-ii/

/*
Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (int i = 0; i < 32; ++i) {
			int cnt = 0;
			for (const auto & j : nums) {
				cnt += 1 & (j >> i);
			}
			result |= (cnt % 3) << i;
		}
		return result;
	}
};