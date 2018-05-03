// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/

/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ? s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sz = nums.size(), i = 0, j = 0, sum = 0, result = 0;
        while (j < sz) {
            sum += nums[j];
            ++j;
            while (sum >= s) {
                if (result == 0 or j - i < result) {
                    result = j - i;
                }
                sum -= nums[i];
                ++i;
            }
        }
        return result;
    }
};
