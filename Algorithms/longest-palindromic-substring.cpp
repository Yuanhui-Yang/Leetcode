5. Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
 

Example:

Input: "cbbd"

Output: "bb"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string t;
        t.push_back('#');
        for (const auto & i : s) {
            t.push_back(i);
            t.push_back('#');
        }
        int sz = t.size(), x = 0, y = 0, max_center = 0, max_len = 0;
        vector<int> A(sz, 0);
        for (int i = 0; i < sz; ++i) {
            int j = 2 * x - i;
            if (j >= 0 and j - A[j] > x - y) {
                A[i] = A[j];
            }
            else {
                int k = 0;
                while (i - k >= 0 and i + k < sz and t[i - k] == t[i + k]) {
                    ++k;
                }
                A[i] = --k;
            }
            if (i + A[i] > x + y) {
                x = i;
                y = A[i];
            }
            if (y > max_len) {
                max_center = x;
                max_len = y;
            }
        }
        return s.substr((max_center - max_len) / 2, max_len);
    }
};

int main(void) {
    Solution solution;
    string s, result;
    
    s = "babad";
    result = solution.longestPalindrome(s);
    cout << result << '\n';

    s = "cbbd";
    result = solution.longestPalindrome(s);
    cout << result << '\n';
    
    return 0;
}