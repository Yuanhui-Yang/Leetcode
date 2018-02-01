316. Remove Duplicate Letters
https://leetcode.com/problems/remove-duplicate-letters/

Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"

#include <iostream>
#include <string>
#include <array>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        array<int, 26> A;
        A.fill(0);
        array<bool, 26> B;
        B.fill(false);
        for (const auto & i : s) {
            int id = i - 'a';
            ++A[id];
        }
        string result;
        for (const auto & i : s) {
            int id = i - 'a';
            if (!B[id]) {
                while (!result.empty() and result.back() >= i and A[result.back() - 'a'] > 0) {
                    B[result.back() - 'a'] = false;
                    result.pop_back();
                }
                result.push_back(i);
                B[id] = true;
            }
            --A[id];
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    string s, result;
    
    s = "bcabc";
    result = solution.removeDuplicateLetters(s);
    cout << result << '\n';
    
    s = "cbacdcbc";
    result = solution.removeDuplicateLetters(s);
    cout << result << '\n';
    
    return 0;
}