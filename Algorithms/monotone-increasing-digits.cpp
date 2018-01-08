738. Monotone Increasing Digits
https://leetcode.com/problems/monotone-increasing-digits/

Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

Example 1:
Input: N = 10
Output: 9
Example 2:
Input: N = 1234
Output: 1234
Example 3:
Input: N = 332
Output: 299
Note: N is an integer in the range [0, 10^9].

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if (N <= 9) {
            return N;
        }
        string s = to_string(N);
        int sz = s.size(), i = 0;
        while (i + 1 < sz and s[i] <= s[i + 1]) {
            ++i;
        }
        if (i + 1 == sz) {
            return N;
        }
        while (i - 1 >= 0 and s[i - 1] == s[i]) {
            --i;
        }
        if (s[i] == '1') {
            s.clear();
            for (i = 0; i + 1 < sz; ++i) {
                s.push_back('9');
            }
            return stoi(s);
        }
        --s[i];
        ++i;
        while (i < sz) {
            s[i] = '9';
            ++i;
        }
        return stoi(s);
    }
};

int main(void) {
    Solution solution;
    int N, result;
    
    N = 10;
    result = solution.monotoneIncreasingDigits(N);
    cout << result << '\n';
    
    N = 1234;
    result = solution.monotoneIncreasingDigits(N);
    cout << result << '\n';

    N = 332;
    result = solution.monotoneIncreasingDigits(N);
    cout << result << '\n';

    return 0;
}