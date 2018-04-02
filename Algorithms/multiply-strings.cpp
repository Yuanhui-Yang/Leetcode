43. Multiply Strings
https://leetcode.com/problems/multiply-strings/

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int sz1 = num1.size(), sz2 = num2.size(), i = sz1 - 1;
        string result(sz1 + sz2, '0');
        while (i >= 0) {
            int j = sz2 - 1, carry = 0;
            while (j >= 0) {
                int value = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
                result[i + j + 1] = value % 10 + '0';
                carry = value / 10;
                --j;
            }
            result[i] += carry;
            --i;
        }
        while (!result.empty() and result.front() == '0') {
            result.erase(result.begin());
        }
        return result.empty() ? "0" : result;
    }
};

int main(void) {
    Solution solution;
    string num1, num2, result;
    
    num1 = "9";
    num2 = "901";
    result = solution.multiply(num1, num2);
    cout << result << '\n';

    return 0;
}
