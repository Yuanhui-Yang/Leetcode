// 537. Complex Number Multiplication
// https://leetcode.com/problems/complex-number-multiplication/

/*
Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
*/

class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0, M = a.size(), N = b.size(), i = 0;
		while (i < M and a[i] != '+') {
			++i;
		}
		x1 = stoi(a.substr(0, i));
		y1 = stoi(a.substr(i + 1, M - 2 - i));
		i = 0;
		while (i < N and b[i] != '+') {
			++i;
		}
		x2 = stoi(b.substr(0, i));
		y2 = stoi(b.substr(i + 1, N - 2 - i));
		return to_string(x1 * x2 - y1 * y2) + "+" + to_string(x1 * y2 + y1 * x2) + "i";
	}
};