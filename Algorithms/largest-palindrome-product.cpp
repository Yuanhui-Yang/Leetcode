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
	int largestPalindrome(int n) {
		if (n <= 0) {
			return 0;
		}
		if (n == 1) {
			return 9;
		}
		long long C = 1337, lower = pow(10, n - 1), upper = pow(10, n);
		for (long long left = upper - 1; left >= lower; --left) {
			string leftStr = to_string(left), rightStr(leftStr);
			reverse(begin(rightStr), end(rightStr));
			long long result = stoll(leftStr + rightStr);
			if (f(result, lower, upper)) {
				return result % C;
			}
		}
		return 0;
	}
private:
	bool f(long long result, long long lower, long long upper) {
		for (long long i = upper - 1; i > 0LL and i >= lower and i * i >= result; --i) {
			if (result % i == 0 and lower <= result / i and result / i < upper) {
				return true;
			}
		}
		return false;
	}
};