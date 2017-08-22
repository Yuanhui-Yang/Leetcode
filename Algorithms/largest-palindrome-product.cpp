// 479. Largest Palindrome Product
// https://leetcode.com/problems/largest-palindrome-product/

/*
Find the largest palindrome made from the product of two n-digit numbers.

Since the result could be very large, you should return the largest palindrome mod 1337.

Example:

Input: 2

Output: 987

Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

Note:

The range of n is [1,8].
*/

class Solution {
public:
	int largestPalindrome(long long n) {
		if (n <= 0) {
			return 0;
		}
		if (n == 1) {
			return 9;
		}
		long long base = 1337;
		for (long long left = pow(10, n) - 1; left >= pow(10, n - 1); --left) {
			string leftStr = to_string(left), rightStr(leftStr);
			reverse(begin(rightStr), end(rightStr));
			string valStr = leftStr + rightStr;
			long long val = stoll(valStr);
			for (long long x = pow(10, n) - 1; x >= sqrt(val); --x) {
				if (val % x == 0) {
					long long y = val / x;
					string yStr = to_string(y);
					if (yStr.size() == n) {
						return val % base;
					}
				}
			}
		}
		return base;
	}
};