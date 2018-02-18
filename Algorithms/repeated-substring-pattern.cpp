459. Repeated Substring Pattern
https://leetcode.com/problems/repeated-substring-pattern/

Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int sz = s.size();
        vector<int> next = f1(s);
        return next[sz] > 0 and ((sz % (sz - next[sz])) == 0);
    }
private:
    vector<int> f1(string & s) {
        int sz = s.size(), i = 0, j = -1;
        vector<int> result(sz + 1);
        result[0] = -1;
        while (i < sz) {
            if (j == -1 or s[i] == s[j]) {
                result[++i] = ++j;
            }
            else {
                j = result[j];
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    string s;
    bool result;

    s = "abab";
    result = solution.repeatedSubstringPattern(s);
    cout << boolalpha << result << '\n';

    s = "aba";
    result = solution.repeatedSubstringPattern(s);
    cout << boolalpha << result << '\n';

    s = "abcabcabcabc";
    result = solution.repeatedSubstringPattern(s);
    cout << boolalpha << result << '\n';

    return 0;
}