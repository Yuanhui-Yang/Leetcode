/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (40.36%)
 * Likes:    517
 * Dislikes: 115
 * Total Accepted:    124.9K
 * Total Submissions: 309.3K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * Note: Do not use any built-in library function such as sqrt.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 14
 * Output: false
 * 
 * 
 * 
 */
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0)
        {
            return false;
        }
        long a = f1(num);
        return a * a == num;
    }
private:
    long f1(long num)
    {
        long i = 1, j = num + 1;
        while (i < j)
        {
            long k = (i + j) >> 1;
            long val = k * k;
            if (val <= num)
            {
                i = k + 1;
            }
            else
            {
                j = k;
            }
            
        }
        return i - 1;
    }
};