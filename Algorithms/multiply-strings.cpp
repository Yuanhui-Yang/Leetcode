// 43. Multiply Strings
// https://leetcode.com/problems/multiply-strings/

/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

class Solution {
public:
	string multiply(string num1, string num2) {
		int M = num1.size(), N = num2.size(), base = 10;
		string result(M + N, '0');
		for (int i = M - 1; i >= 0; --i) {
			int carry = 0, x = num1[i] - '0';
			for (int j = N - 1; j >= 0; --j) {
				int y = num2[j] - '0', z = x * y + carry + result[i + j + 1] - '0';
				carry = z / base;
				z %= base;
				result[i + j + 1] = '0' + z;
			}
			result[i] += carry;
		}
		while (!result.empty() and result.front() == '0') {
			result.erase(begin(result));
		}
		return result.empty() ? string("0") : result;
	}
};