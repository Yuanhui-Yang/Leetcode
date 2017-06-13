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
		if (num1 == "0" or num2 == "0") {
			return "0";
		}
		size_t m = num1.size(), n = num2.size(), base = 10, k = m + n - 1;
		string result(m + n, '0');
		for (size_t i = m - 1; i != string::npos; --i) {
			size_t carry = 0, j = n - 1, x = num1[i] - '0';
			k = i + j + 1;
			while (carry or j != string::npos) {
				size_t y = j != string::npos ? (num2[j--] - '0') : 0;
				size_t z = x * y + carry + (result[k] - '0');
				result[k] = '0' + z % base;
				--k;
				carry = z / base;
			}
		}
		return result.substr(k + 1);
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