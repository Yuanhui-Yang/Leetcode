// 678. Valid Parenthesis String
// https://leetcode.com/problems/valid-parenthesis-string/

/*
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool checkValidString(string s) {
		int sz = s.size(), i, x, y;
		char ch;
		stack<int> a, b;
		for (i = 0; i < sz; ++i) {
			ch = s[i];
			if (ch == '(') {
				a.push(i);
			}
			else if (ch == '*') {
				b.push(i);
			}
			else if (ch == ')') {
				if (!a.empty()) {
					a.pop();
				}
				else if (!b.empty()) {
					b.pop();
				}
				else {
					return false;
				}
			}
		}
		while (!a.empty() and !b.empty()) {
			x = a.top();
			y = b.top();
			if (x < y) {
				a.pop();
				b.pop();
			}
			else {
				return false;
			}
		}
		return a.empty();
	}
};
 
int main(void) {
	Solution solution;
	string s;
	bool result;
	
	s = "()";
	result = solution.checkValidString(s);
	cout << boolalpha << result << '\n';

	s = "(*)";
	result = solution.checkValidString(s);
	cout << boolalpha << result << '\n';

	s = "(*))";
	result = solution.checkValidString(s);
	cout << boolalpha << result << '\n';

	s = "(())((())()()(*)(*()(())())())()()((()())((()))(*";
	result = solution.checkValidString(s);
	cout << boolalpha << result << '\n';

	return 0;
}