// 32. Longest Valid Parentheses
// https://leetcode.com/problems/longest-valid-parentheses/

/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> stk;
		stk.push(-1);
		int result = 0;
		for (int n = s.size(), i = 0; i < n; ++i) {
			if (stk.top() == -1 or s[i] == '(') {
				stk.push(i);
				continue;
			}
			if (s[stk.top()] == '(') {
				stk.pop();
				result = max(result, i - stk.top());
				continue;
			}
			stk.push(i);
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	string s;
	int answer, result;

	s = "())()()(())((()(()()(((()))((((())((()(())()())(()((((()))()(()))(())()(())(()(((((())((((((()())())(()(()((())()))(()))))))()(()))((((())()()()))()()()(((()(()())(()()(()(()()(((()))))))()()))())())((()()))))))((()))(((()((())()(()()))((())))()()())))))))()))))(()))))()))()))()((())))((()))(()))))))(((()))))))))()(()()()(())((())()))()()(())))()()))(()())()))(((()())()))((())((((()))(()(()(()()()(((())()(((((()))((()(((((())(()()))((((((((()(()(()(()(())))(())(()())())(()((((()(())((()(())))(())))()(((((()(()()(())))))))())(())(())(()()(((())))((()))(((((()))))())))()((()))()))))())))))((())(((((()()))((((())))(((()(()(())())(((()(()(()()()())))())()))((()((())())()()()(((())(((((()((((((()((()())))((((())((()(((((((()(()((()()()(()(()())(()(()()((((())))()(((()())))(()()))()(()()()()(((((())(()))))((()))())))()((((((()))())))()(()))(())))((((()())(((((()()())(((((())(()())(()))))()(()()))()))))))())))(((())(()(()()))(()))()(((())))())((((()(((()))))))()(()(()))()()(()()))))))))((()))))))(())((()((()))()))((((((()())))))(()((())((((()))))(()(()()()()(()))()()(()(()))(()()(((((((()())(())(()())((())())()(()())((())()())())(()())))())))(())())())(())((()())(((()()))()))()()))()(()(())((((((((())))()((())((()((((((((((()))))(()(((((())(()(()())())))((())())))))()))(()((()()))((()((())()()()((()(())())((())())(()()(((())))))())()()(()))()())(()(()((())))((((()()(())))())(())(()(()(())())())(()()())()(())())))(()()(((())))((()()(((())()()(()())((((()()(()())(()((((()(()()(()(()(((()((()())(()()))(()((((()(((((()))))()()))(((()((((((()(()()()()())()))(()(())))))((()(((()())())))(((()()))(()(()(((((((()()))(()(())))())()(())())(())(()))(())(()))()()(()()())))))()))()((())(((()((((((((())()()))())))((()())(";
	answer = 310;
	result = solution.longestValidParentheses(s);
	assert(answer == result);

	s = "()()";
	answer = 4;
	result = solution.longestValidParentheses(s);
	assert(answer == result);

	s = ")()())()()(";
	answer = 4;
	result = solution.longestValidParentheses(s);
	assert(answer == result);

	s = "(()";
	answer = 2;
	result = solution.longestValidParentheses(s);
	assert(answer == result);

	s = ")()())";
	answer = 4;
	result = solution.longestValidParentheses(s);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}