/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 *
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Easy (32.62%)
 * Likes:    373
 * Dislikes: 247
 * Total Accepted:    50.4K
 * Total Submissions: 154.6K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer c, your task is to decide whether there're two
 * integers a and b such that a^2 + b^2 = c.
 * 
 * Example 1:
 * 
 * 
 * Input: 5
 * Output: True
 * Explanation: 1 * 1 + 2 * 2 = 5
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: False
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c < 0)
        {
            return false;
        }
        return f1(c);
    }
private:
    bool f1(long c)
    {
        for (long i = sqrt(c); i >= 0; --i)
        {
            long j = c - i * i;
            long k = sqrt(j);
            if (k * k == j)
            {
                return true;
            }
        }
        return false;
    }
};