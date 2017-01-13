// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		vector<char> stack;
		for (size_t i = 0; i < s.size(); i++) {
			const char c = s[i];
			if (stack.empty()) {
				if (c == '(' || c == '[' || c == '{') {
					stack.push_back(c);
					continue;
				}
				return false;
			}
			const char stack_back = stack.back();
			if (stack_back == '(' || stack_back == '[' || stack_back == '{') {
				if (c == '(' || c == '[' || c == '{') {
					stack.push_back(c);
					continue;
				}
				if (stack_back == '(') {
					if (c == ')') {
						stack.pop_back();
						continue;
					}
					return false;
				}
				if (stack_back == '[') {
					if (c == ']') {
						stack.pop_back();
						continue;
					}
					return false;
				}
				if (stack_back == '{') {
					if (c == '}') {
						stack.pop_back();
						continue;
					}
					return false;
				}
				return false;
			}
			return false;
		}
		return stack.empty();
	}
};
int main(void) {
	Solution solution;
	bool result;

	result = solution.isValid("()");
	assert(true == result);

	result = solution.isValid("()[]{}");
	assert(true == result);

	result = solution.isValid("(]");
	assert(false == result);

	result = solution.isValid("([)]");
	assert(false == result);

	cout << "\nPassed All\n";
	return 0;
}