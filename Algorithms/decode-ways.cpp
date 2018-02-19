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
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int sz = s.size(), i = sz - 1;
        if (sz == 0) {
            return 0;
        }
        vector<int> A(sz + 1);
        A[sz] = 1;
        while (i >= 0) {
            if (s[i] == '0') {
                A[i] = 0;
            }
            else if (i + 2 <= sz) {
                int x = stoi(s.substr(i, 2));
                if (x <= 26) {
                    A[i] = A[i + 1] + A[i + 2];
                }
                else {
                    A[i] = A[i + 1];
                }
            }
            else {
                A[i] = A[i + 1];
            }
            --i;
        }
        return A[0];
    }
};

int main(void) {
    Solution solution;
    string s;
    int answer, result;

    s = "";
    answer = 0;
    result = solution.numDecodings(s);
    cout << result << '\n';

    s = "12";
    answer = 2;
    result = solution.numDecodings(s);
    cout << result << '\n';

    s = "27";
    answer = 1;
    result = solution.numDecodings(s);
    cout << result << '\n';

    s = "00";
    answer = 0;
    result = solution.numDecodings(s);
    cout << result << '\n';

    s = "01";
    answer = 0;
    result = solution.numDecodings(s);
    cout << result << '\n';

    s = "012";
    answer = 0;
    result = solution.numDecodings(s);
    cout << result << '\n';

    s = "111";
    result = solution.numDecodings(s);
    cout << result << '\n';

    s = "230";
    result = solution.numDecodings(s);
    cout << result << '\n';

    s = "6065812287883668764831544958683283296479682877898293612168136334983851946827579555449329483852397155";
    result = solution.numDecodings(s);
    cout << result << '\n';

    return 0;
}