32. Longest Valid Parentheses
https://leetcode.com/problems/longest-valid-parentheses/

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int sz = s.size(), result = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < sz; ++i) {
            if (stk.top() == -1) {
                stk.push(i);
            }
            else if (s[i] == '(') {
                stk.push(i);
            }
            else if (s[i] == ')') {
                if (s[stk.top()] == '(') {
                    stk.pop();
                    result = max(result, i - stk.top());   
                }
                else {
                    stk.push(i);
                }
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    string s;
    int result;
    
    s = ")()())";
    result = solution.longestValidParentheses(s);
    cout << result << '\n';
    
    return 0;
}