// 233. Number of Digit One
// https://leetcode.com/problems/number-of-digit-one/

/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
*/

class Solution {
public:
	int countDigitOne(long long n) {
		long long result = 0;
		for (long long m = log10(n) + 1, x = 1LL, y = 0LL, i = 1LL; i <= m; ++i) {
			y = x;
			x *= 10LL;
			result += n / x * y + min(y, max(0LL, n % x - y + 1LL));
		}
		return result;
	}
};