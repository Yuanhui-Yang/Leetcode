// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> stk;
		for (const auto &i : s) {
			switch (i) {
				case '(':
				case '[':
				case '{': stk.push(i); break;
				case ')': if (stk.empty() or stk.top() != '(') return false; stk.pop(); break;
				case ']': if (stk.empty() or stk.top() != '[') return false; stk.pop(); break;
				case '}': if (stk.empty() or stk.top() != '{') return false; stk.pop(); break;
			}
		}
		return stk.empty();
	}
};

int main(void) {
	Solution solution;
	string s;
	bool answer, result;

	s = "()";
	answer = true;
	result = solution.isValid(s);
	assert(answer == result);

	s = "()[]{}";
	answer = true;
	result = solution.isValid(s);
	assert(answer == result);

	s = "(]";
	answer = false;
	result = solution.isValid(s);
	assert(answer == result);

	s = "([)]";
	answer = false;
	result = solution.isValid(s);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
