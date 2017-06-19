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

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		int m = num1.size(), n = num2.size(), base = 10;
		string result(m + n, '0');
		for (int i = m - 1; i >= 0; --i) {
			int a = num1[i] - '0', carry = 0;
			for (int j = n - 1; j >= 0; --j) {
				int b = num2[j] - '0';
				int c = a * b + carry + result[i + j + 1] - '0';
				carry = c / base;
				c %= base;
				result[i + j + 1] = c + '0';
			}
			result[i] += carry;
		}
		int k = 0;
		while (k < m + n and result[k] == '0') {
			++k;
		}
		return k < m + n ? result.substr(k) : "0";
	}
};

int main(void) {
	Solution solution;
	string num1, num2, answer, result;

	num1 = "9133";
	num2 = "0";
	answer = "0";
	result = solution.multiply(num1, num2);
	assert(answer == result);

	num1 = "1234";
	num2 = "345";
	answer = "425730";
	result = solution.multiply(num1, num2);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}