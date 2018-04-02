415. Add Strings
https://leetcode.com/problems/add-strings/

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int sz1 = num1.size(), sz2 = num2.size(), i = sz1 - 1, j = sz2 - 1, k = max(sz1, sz2), carry = 0;
        string result(k + 1, '0');
        while (i >= 0 or j >= 0 or carry > 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int z = carry + x + y;
            result[k] = z % 10 + '0';
            carry = z / 10;
            --i;
            --j;
            --k;
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
    
    num1 = "1010109123788890008661112233456896650111";
    num2 = "90128489218949821413535333411289000";
    result = solution.addStrings(num1, num2);
    cout << result << '\n';
    
    return 0;
}
