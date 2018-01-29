301. Remove Invalid Parentheses
https://leetcode.com/problems/remove-invalid-parentheses/

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]

#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        f1(result, s, 0, 0, {'(', ')'});
        return result;
    }
private:
    void f1(vector<string> & result, string s, int last_i, int last_j, array<char, 2> par) {
        for (int sz = s.size(), i = last_i, stack = 0; i < sz; ++i) {
            if (s[i] == par[0]) {
                ++stack;
            }
            else if (s[i] == par[1]) {
                --stack;
            }
            if (stack < 0) {
                for (int j = last_j; j <= i; ++j) {
                    if (s[j] == par[1] and (j == last_j or s[j] != s[j - 1])) {
                        f1(result, s.substr(0, j) + s.substr(j + 1), i, j, par);
                    }
                }
                return;
            }
        }
        reverse(s.begin(), s.end());
        if (par[0] == '(') {
            f1(result, s, 0, 0, {')', '('});
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