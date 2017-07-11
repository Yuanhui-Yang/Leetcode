// 238. Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/

/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int left = 1, right = 1, n = nums.size();
		vector<int> result(n, 1);
		for (int i = 0; i < n; ++i) {
			result[i] *= left;
			left *= nums[i];
		}
		for (int i = n - 1; i >= 0; --i) {
			result[i] *= right;
			right *= nums[i];
		}
		return result;
	}
};