44. Wildcard Matching
https://leetcode.com/problems/wildcard-matching/

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sz1 = s.size(), sz2 = p.size();
        vector<vector<bool>> A(sz1 + 1, vector<bool>(sz2 + 1, false));
        A[0][0] = true;
        for (int i = 0; i <= sz1; ++i) {
            for (int j = 1; j <= sz2; ++j) {
                if (p[j - 1] == '*') {
                    for (int k = 0; k <= i; ++k) {
                        if (A[k][j - 1]) {
                            A[i][j] = true;
                            break;
                        }
                    }
                }
                else if (i > 0 and p[j - 1] == '?') {
                    A[i][j] = A[i - 1][j - 1];
                }
                else if (i > 0 and s[i - 1] == p[j - 1]) {
                    A[i][j] = A[i - 1][j - 1];
                }
            }
        }
        return A[sz1][sz2];
    }
};

int main(void) {
    Solution solution;
    string s, p;
    bool answer, result;

    s = "";
    p = "*";
    result = solution.isMatch(s, p);
    cout << boolalpha << result << '\n';

    s = "aa";
    p = "a";
    result = solution.isMatch(s, p);
    cout << boolalpha << result << '\n';

    s = "aa";
    p = "aa";
    result = solution.isMatch(s, p);
    cout << boolalpha << result << '\n';

    s = "aa";
    p = "aaa";
    result = solution.isMatch(s, p);
    cout << boolalpha << result << '\n';

    s = "aa";
    p = "*";
    result = solution.isMatch(s, p);
    cout << boolalpha << result << '\n';

    s = "aa";
    p = "a*";
    result = solution.isMatch(s, p);
    cout << boolalpha << result << '\n';

    s = "aa";
    p = "?*";
    result = solution.isMatch(s, p);
    cout << boolalpha << result << '\n';

    s = "aab";
    p = "c*a*b";
    result = solution.isMatch(s, p);
    cout << boolalpha << result << '\n';

    return 0;
}