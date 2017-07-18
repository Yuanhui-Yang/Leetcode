// 415. Add Strings
// https://leetcode.com/problems/add-strings/

/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

class Solution {
public:
	string addStrings(string num1, string num2) {
		int M = num1.size(), N = num2.size(), i = M - 1, j = N - 1, k = max(M, N), carry = 0, base = 10;
		string result(k + 1, '0');
		while (i >= 0 or j >= 0 or carry > 0) {
			int x = i >= 0 ? num1[i--] - '0' : 0;
			int y = j >= 0 ? num2[j--] - '0' : 0;
			int z = x + y + carry;
			carry = z / base;
			z %= base;
			result[k--] = '0' + z;
		}
		while (!result.empty() and result.front() == '0') {
			result.erase(begin(result));
		}
		return result.empty() ? string("0") : result;
	}
};