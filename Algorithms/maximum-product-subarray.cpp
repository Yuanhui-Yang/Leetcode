// 152. Maximum Product Subarray
// https://leetcode.com/problems/maximum-product-subarray/

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int result = nums.front(), a = nums.front(), b = nums.front();
		for (int n = nums.size(), i = 1; i < n; ++i) {
			int x = a, y = b;
			a = min(nums[i], min(nums[i] * x, nums[i] * y));
			b = max(nums[i], max(nums[i] * x, nums[i] * y));
			result = max(result, max(a, b));
		}
		return result;
	}
};