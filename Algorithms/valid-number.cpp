// 65. Valid Number
// https://leetcode.com/problems/valid-number/

/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		if (s.empty()) {
		return false;
		}
		int n = s.size(), i = 0, dot = -1;
		while (i < n and s[i] == ' ') {
			++i;
		}
		if (i >= n or !(isdigit(s[i]) or s[i] == '+' or s[i] == '-' or s[i] == '.')) {
			return false;
		}
		if (s[i] == '+' or s[i] == '-') {
			if (i + 1 >= n or !(isdigit(s[i + 1]) or s[i + 1] == '.')) {
				return false;
			}
			++i;
		}
		if (s[i] == '.') {
			if (i + 1 >= n or !isdigit(s[i + 1])) {
				return false;
			}
			dot = i;
			++i;
		}
		while (i < n and isdigit(s[i])) {
			++i;
		}
		if (i >= n) {
			return true;
		}
		if (!(s[i] == '.' or s[i] == 'e' or s[i] == ' ')) {
			return false;
		}
		if (s[i] == '.') {
			if (dot >= 0) {
				return false;
			}
			if (i + 1 >= n) {
				return true;
			}
			if (!(isdigit(s[i + 1]) or s[i + 1] == 'e' or s[i + 1] == ' ')) {
				return false;
			}
			++i;
		}
		while (i < n and isdigit(s[i])) {
			++i;
		}
		if (s[i] == 'e') {
			if (i + 1 >= n or !(isdigit(s[i + 1]) or s[i + 1] == '+' or s[i + 1] == '-')) {
				return false;
			}
			++i;
		}
		if (s[i] == '+' or s[i] == '-') {
			if (i + 1 >= n and !isdigit(s[i + 1])) {
				return false;
			}
			++i;
		}
		while (i < n and isdigit(s[i])) {
			++i;
		}
		while (i < n and s[i] == ' ') {
			++i;
		}
		return i >= n;
	}
};

int main(void) {
	Solution solution;
	string s;
	bool answer, result;

	s = " 005047e+6";
	answer = true;
	result = solution.isNumber(s);
	assert(answer == result);

	s = "1.431352e7";
	answer = true;
	result = solution.isNumber(s);
	assert(answer == result);

	s = "3. ";
	answer = true;
	result = solution.isNumber(s);
	assert(answer == result);

	s = ".1";
	answer = true;
	result = solution.isNumber(s);
	assert(answer == result);

	s = "1 ";
	answer = true;
	result = solution.isNumber(s);
	assert(answer == result);

	s = "1 ";
	answer = true;
	result = solution.isNumber(s);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}