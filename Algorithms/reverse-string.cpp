// 344. Reverse String
// https://leetcode.com/problems/reverse-string/

/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string reverseString(string s) {
		int n = s.size(), i = 0, j = n - 1;
		while (i < j) {
			swap(s[i++], s[j--]);
		}
		return s;
	}
};

int main(void) {
	Solution solution;
	string s, answer, result;

	s = "hello";
	answer = "olleh";
	result = solution.reverseString(s);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}