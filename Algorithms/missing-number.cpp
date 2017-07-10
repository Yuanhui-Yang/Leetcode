// 268. Missing Number
// https://leetcode.com/problems/missing-number/

/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		return nums.size() * (nums.size() + 1) / 2 - accumulate(begin(nums), end(nums), 0);
	}
};