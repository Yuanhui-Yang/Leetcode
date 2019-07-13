1118. Number of Days in a Month
https://leetcode.com/problems/number-of-days-in-a-month/

Given a year Y and a month M, return how many days there are in that month.

 

Example 1:

Input: Y = 1992, M = 7
Output: 31
Example 2:

Input: Y = 2000, M = 2
Output: 29
Example 3:

Input: Y = 1900, M = 2
Output: 28
 

Note:

1583 <= Y <= 2100
1 <= M <= 12

class Solution {
public:
    int numberOfDays(int Y, int M) {
        array<int, 12> A = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        --M;
        if (M == 1)
        {
            int other = Y % 100 ? Y % 4 == 0 : Y % 400 == 0;
            return A[M] + other;
        }
        else
        {
            return A[M];
        }
    }
};