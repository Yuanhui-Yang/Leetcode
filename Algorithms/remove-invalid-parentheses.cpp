301. Remove Invalid Parentheses
https://leetcode.com/problems/remove-invalid-parentheses/

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        f1(result, s, "()", 0, 0);
        return result;
    }
private:
    void f1(vector<string> & result, string s, string pars, int start1, int start2) {
        for (int sz = s.size(), stk = 0, i = start1; i < sz; ++i) {
            char ch = s[i];
            if (ch == pars[0]) {
                ++stk;
            }
            else if (ch == pars[1]) {
                --stk;
            }
            if (stk < 0) {
                for (int j = start2; j <= i; ++j) {
                    if (s[j] == pars[1]) {
                        if (j == start2 or s[j - 1] != s[j]) {
                            f1(result, s.substr(0, j) + s.substr(j + 1), pars, i, j);
                        }
                    }
                }
                return;
            }
        }
        reverse(s.begin(), s.end());
        if (pars[0] == '(') {
            reverse(pars.begin(), pars.end());
            f1(result, s, pars, 0, 0);
        }
        else {
            result.push_back(s);
        }
    }
};

int main(void) {
    Solution solution;
    string s;
    vector<string> result;
    
    s = "()())()";
    result = solution.removeInvalidParentheses(s);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    s = "(a)())()";
    result = solution.removeInvalidParentheses(s);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    s = ")(";
    result = solution.removeInvalidParentheses(s);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';
    
    return 0;
}
