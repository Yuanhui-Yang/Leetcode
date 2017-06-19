// 67. Add Binary
// https://leetcode.com/problems/add-binary/

/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int m = a.size(), n = b.size(), i = m - 1, j = n - 1, k = max(m, n), carry = 0, base = 2;
		string result(k + 1, '0');
		while (carry or i >= 0 or j >= 0) {
			int x = i >= 0 ? a[i--] - '0' : 0;
			int y = j >= 0 ? b[j--] - '0' : 0;
			int z = x + y + carry;
			carry = z / base;
			z %= base;
			result[k--] = '0' + z;
		}
		return result.substr(k + 1);
	}
};

int main(void) {
	Solution solution;
	string a, b, answer, result;

	a = "1000";
	b = "1110101";
	answer = "1111101";
	result = solution.addBinary(a, b);
	assert(answer == result);

	a = "0";
	b = "0";
	answer = "0";
	result = solution.addBinary(a, b);
	assert(answer == result);

	a = "11";
	b = "1";
	answer = "100";
	result = solution.addBinary(a, b);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}