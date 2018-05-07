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
        int sz = nums.size();
        vector<int> result(sz);
        for (int i = sz - 1, val = 1; i >= 0; --i) {
            result[i] = val;
            val *= nums[i];
        }
        for (int i = 0, val = 1; i < sz; ++i) {
            result[i] *= val;
            val *= nums[i];
        }
        return result;
    }
};
