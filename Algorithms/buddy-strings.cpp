859. Buddy Strings
https://leetcode.com/problems/buddy-strings/

Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

 

Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false
 

Note:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist only of lowercase letters.

#include <iostream>
#include <array>
#include <string>

using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        else if (A.size() < 2) {
            return false;
        }
        else if (A == B) {
            array<int, 26> X;
            X.fill(0);
            for (const auto & ch : A) {
                int id = ch - 'a';
                if (++X[id] >= 2) {
                    return true;
                }
            }
            return false;
        }
        else {
            int sz = A.size(), x = -1, y = -1;
            for (int i = 0; i < sz; ++i) {
                if (A[i] != B[i]) {
                    if (x < 0) {
                        x = i;
                    }
                    else if (y < 0) {
                        y = i;
                    }
                    else {
                        return false;
                    }
                }
            }
            return x >= 0 and y >= 0 and A[x] == B[y] and A[y] == B[x];
        }
    }
};

int main(void) {
    Solution solution;
    string A, B;
    bool result;
    
    A = "ab";
    B = "ba";
    result = solution.buddyStrings(A, B);
    cout << boolalpha << result << '\n';

    A = "ab";
    B = "ab";
    result = solution.buddyStrings(A, B);
    cout << boolalpha << result << '\n';

    A = "aa";
    B = "aa";
    result = solution.buddyStrings(A, B);
    cout << boolalpha << result << '\n';

    A = "aaaaaaabc";
    B = "aaaaaaacb";
    result = solution.buddyStrings(A, B);
    cout << boolalpha << result << '\n';

    A = "";
    B = "aa";
    result = solution.buddyStrings(A, B);
    cout << boolalpha << result << '\n';
    
    return 0;
}