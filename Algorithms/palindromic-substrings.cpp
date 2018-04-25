647. Palindromic Substrings
https://leetcode.com/problems/palindromic-substrings/

Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        string t;
        t.push_back('#');
        for (const auto & i : s) {
            t.push_back(i);
            t.push_back('#');
        }
        int sz = t.size(), x = 0, y = 0;
        vector<int> A(sz, 0);
        for (int i = 0; i < sz; ++i) {
            int j = 2 * x - i;
            if (j >= 0 and x - y < j - A[j]) {
                A[i] = A[j];
            }
            else {
                int k = 0;
                while (i - k >= 0 and i + k < sz and t[i - k] == t[i + k]) {
                    ++k;
                }
                A[i] = --k;
            }
            if (x + y < i + A[i]) {
                x = i;
                y = A[i];
            }
        }
        int result = 0;
        for (const auto & i : A) {
            result += (i + 1) / 2;
        }
        return result;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int sz = s.size(), result = 0;
        for (int i = 0; i < sz; ++i) {
            int x = i, y = i;
            while (x >= 0 and y < sz and s[x] == s[y]) {
                ++result;
                --x;
                ++y;
            }
        }
        for (int i = 0 ; i + 1 < sz; ++i) {
            int x = i, y = i + 1;
            while (x >= 0 and y < sz and s[x] == s[y]) {
                ++result;
                --x;
                ++y;
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    string s;
    int result;

    s = "abc";
    result = solution.countSubstrings(s);
    cout << result << '\n';

    s = "aaa";
    result = solution.countSubstrings(s);
    cout << result << '\n';

    return 0;
}
