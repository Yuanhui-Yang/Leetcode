639. Decode Ways II
https://leetcode.com/problems/decode-ways-ii/

A message containing letters from A-Z is being encoded to numbers using the following mapping way:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:
Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
Example 2:
Input: "1*"
Output: 9 + 9 = 18
Note:
The length of the input string will fit in range [1, 105].
The input string will only contain the character '*' and digits '0' - '9'.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        return f3(s);
    }
private:
    long f1(string & s) {
        int sz = s.size();
        if (sz == 0) {
            return 1;
        }
        long NUM = 1e9 + 7;
        vector<long> A(sz + 1, 0);
        A[0] = 1;
        A[1] = f2(s[0]);
        for (int i = 2; i <= sz; ++i) {
            A[i] = f2(s[i - 1]) * A[i - 1];
            A[i] += f2(s[i - 2], s[i - 1]) * A[i - 2];
            A[i] %= NUM;
        }
        return A[sz];
    }
    long f2(char a) {
        return a == '*' ? 9 : a != '0';
    }
    long f2(char a, char b) {
        if (a == '0') {
            return 0;
        }
        if (a == '*' and b == '*') {
            return 15;
        }
        if (a == '*') {
            return '0' <= b and b <= '6' ? 2 : 1;
        }
        if (b == '*') {
            if (a == '1') {
                return 9;
            }
            if (a == '2') {
                return 6;
            }
            return 0;
        }
        int val = a - '0';
        val = 10 * val;
        val += b - '0';
        return val <= 26 ? 1 : 0;
    }
    long f3(string & s) {
        int sz = s.size();
        if (sz == 0) {
            return 1;
        }
        long NUM = 1e9 + 7, a = 1, b = f2(s[0]);
        for (int i = 2; i <= sz; ++i) {
            long c = f2(s[i - 1]) * b;
            c += f2(s[i - 2], s[i - 1]) * a;
            c %= NUM;
            a = b;
            b = c;
        }
        return b;
    }
};

int main(void) {
    Solution solution;
    string s;
    int result;

    s = "*";
    result = solution.numDecodings(s);
    cout << result << '\n';

    s = "1*";
    result = solution.numDecodings(s);
    cout << result << '\n';

    return 0;
}
