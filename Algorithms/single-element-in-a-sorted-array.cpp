// 540. Single Element in a Sorted Array
// https://leetcode.com/problems/single-element-in-a-sorted-array/

/*
Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10
Note: Your solution should run in O(log n) time and O(1) space.
*/

class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int sz = nums.size(), i = 0, j = sz;
		while (i < j) {
			int k = i + (j - i) / 2;
			if (k + 1 < sz and nums[k] == nums[k + 1] and k % 2 == 0) {
				i = k + 1;
			}
			else if (k + 1 < sz and nums[k] != nums[k + 1] and k % 2 == 1) {
				i = k + 1;
			}
			else {
				j = k;
			}
		}
		return nums[i];
	}
};