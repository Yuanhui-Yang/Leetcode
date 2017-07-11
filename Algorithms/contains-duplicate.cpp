// 217. Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/

/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		sort(begin(nums), end(nums));
		for (int n = nums.size(), i = 1; i < n; ++i) {
			if (nums[i - 1] == nums[i]) {
				return true;
			}
		}
		return false;
	}
};