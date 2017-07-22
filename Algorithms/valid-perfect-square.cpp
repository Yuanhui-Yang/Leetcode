// 367. Valid Perfect Square
// https://leetcode.com/problems/valid-perfect-square/

/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
*/

class Solution {
public:
	bool isPerfectSquare(long long num) {
		long long left = 1, right = num;
		while (left < right) {
			long long mid = (left + right) / 2;
			if (mid * mid < num) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return left * left == num;
	}
};