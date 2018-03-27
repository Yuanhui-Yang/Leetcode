214. Shortest Palindrome
https://leetcode.com/problems/shortest-palindrome/

Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int sz = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        s.push_back('#');
        s.append(t);
        vector<int> A = f1(s);
        string result;
        result = t.substr(0, sz - A.back());
        result.append(s.substr(0, sz));
        return result;
    }
private:
    vector<int> f1(string & s) {
        int sz = s.size();
        vector<int> result(sz + 1);
        result[0] = -1;
        int i = 0, j = -1;
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

int main() {
    Solution solution;
    string s, result;
    
    s = "aacecaaa";
    result = solution.shortestPalindrome(s);
    cout << result << '\n';

    s = "abcd";
    result = solution.shortestPalindrome(s);
    cout << result << '\n';
    
    return 0;
}
