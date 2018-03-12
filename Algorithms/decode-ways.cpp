91. Decode Ways
https://leetcode.com/problems/decode-ways/

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int sz = s.size();
        if (sz == 0) {
            return 0;
        }
        int curr = s[sz - 1] != '0', prev = 1, i = sz - 2;
        while (i >= 0) {
            if (s[i] == '0') {
                prev = curr;
                curr = 0;
            }
            else {
                int val = stoi(s.substr(i, 2));
                if (val <= 26) {
                    int next = curr + prev;
                    prev = curr;
                    curr = next;
                }
                else {
                    int next = curr;
                    prev = curr;
                    curr = next;
                }
            }
            --i;
        } 
        return curr;
    }
};

int main(void) {
    Solution solution;
    string s;
    int result;

    s = "12";
    result = solution.numDecodings(s);
    cout << result << '\n';

    return 0;
}