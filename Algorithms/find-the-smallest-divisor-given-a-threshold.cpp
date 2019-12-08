/*
 * @lc app=leetcode id=1283 lang=cpp
 *
 * [1283] Find the Smallest Divisor Given a Threshold
 *
 * https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
 *
 * algorithms
 * Medium (32.04%)
 * Likes:    35
 * Dislikes: 13
 * Total Accepted:    2.7K
 * Total Submissions: 8.3K
 * Testcase Example:  '[1,2,5,9]\n6'
 *
 * Given an array of integers nums and an integer threshold, we will choose a
 * positive integer divisor and divide all the array by it and sum the result
 * of the division. Find the smallest divisor such that the result mentioned
 * above is less than or equal to threshold.
 * 
 * Each result of division is rounded to the nearest integer greater than or
 * equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
 * 
 * It is guaranteed that there will be an answer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,5,9], threshold = 6
 * Output: 5
 * Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
 * If the divisor is 4 we can get a sum to 7 (1+1+2+3) and if the divisor is 5
 * the sum will be 5 (1+1+1+2). 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,3,5,7,11], threshold = 11
 * Output: 3
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [19], threshold = 5
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5 * 10^4
 * 1 <= nums[i] <= 10^6
 * nums.length <= threshold <= 10^6
 * 
 */

// @lc code=start
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        while (left < right)
        {
            int mid = (left + right) >> 1;
            int tmp = f1(nums, mid);
            if (tmp > threshold)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
private:
    int f1(vector<int>& nums, int divisor)
    {
        int result = 0;
        for (const auto& num : nums)
        {
            int tmp = num / divisor;
            result += (num % divisor == 0 ? tmp : tmp + 1);
        }
        return result;
    }
};
// @lc code=end

