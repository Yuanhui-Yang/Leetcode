// 34. Search for a Range
// https://leetcode.com/problems/search-for-a-range/

/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int n = nums.size(), i = 0, j = n;
		vector<int> result({-1, -1});
		while (i < j) {
			int k = i + (j - i) / 2;
			if (nums[k] < target) {
				i = k + 1;
			}
			else {
				j = k;
			}
		}
		if (i < n and nums[i] == target) {
			result[0] = i;
		}
		i = 0;
		j = n;
		while (i < j) {
			int k = i + (j - i) / 2;
			if (nums[k] <= target) {
				i = k + 1;
			}
			else {
				j = k;
			}
		}
		if (i > 0 and nums[i - 1] == target) {
			result[1] = i - 1;
		}
		return result;
	}
};