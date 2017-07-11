// 219. Contains Duplicate II
// https://leetcode.com/problems/contains-duplicate-ii/

/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
*/

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> dict;
		for (int n = nums.size(), i = 0; i < n; ++i) {
			if (dict.count(nums[i]) and i - dict[nums[i]] <= k) {
				return true;
			}
			dict[nums[i]] = i;
		}
		return false;
	}
};