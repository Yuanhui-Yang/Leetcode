// 628. Maximum Product of Three Numbers
// https://leetcode.com/problems/maximum-product-of-three-numbers/

/*
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24
Note:
The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
*/

class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		int result = numeric_limits<int>::min();
		sort(begin(nums), end(nums));
		for (int n = nums.size(), i = 0; i + 2 < n; ++i) {
			int j = i + 1, k = n - 1, p = nums[j] * nums[k];
			if (nums[i] < 0) {
				result = max(result, nums[i] * p);
			}
			else if (nums[i] == 0) {
				result = max(result, 0);
			}
			else {
				result = max(result, nums[i] * max(nums[j] * nums[j + 1], nums[k - 1] * nums[k]));
			}
		}
		return result;
	}
};