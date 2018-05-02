20. Valid Parentheses
https://leetcode.com/problems/valid-parentheses/

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (const auto & i : s) {
            if (stk.empty()) {
                stk.push(i);
            }
            else if (i == ')') {
                if (stk.top() == '(') {
                    stk.pop();
                }
                else {
                    return false;
                }
            }
            else if (i == ']') {
                if (stk.top() == '[') {
                    stk.pop();
                }
                else {
                    return false;
                }
            }
            else if (i == '}') {
                if (stk.top() == '{') {
                    stk.pop();
                }
                else {
                    return false;
                }
            }
            else {
                stk.push(i);
            }
        }
        return stk.empty();
    }
};

int main(void) {
    Solution solution;
    string s;
    bool result;

    s = "()";
    result = solution.isValid(s);
    cout << boolalpha << result << '\n';

    s = "()[]{}";
    result = solution.isValid(s);
    cout << boolalpha << result << '\n';

    s = "(]";
    result = solution.isValid(s);
    cout << boolalpha << result << '\n';

    s = "([)]";
    result = solution.isValid(s);
    cout << boolalpha << result << '\n';

    return 0;
}
