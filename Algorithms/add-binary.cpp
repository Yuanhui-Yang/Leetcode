// 67. Add Binary
// https://leetcode.com/problems/add-binary/

/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int sz1 = a.size(), sz2 = b.size(), sz3 = max(sz1, sz2) + 1, carry = 0, i = sz1 - 1, j = sz2 - 1, k = sz3 - 1;
        string result(sz3, '0');
        while (i >= 0 or j >= 0 or carry > 0) {
            int x = i >= 0 ? a[i] - '0' : 0;
            int y = j >= 0 ? b[j] - '0' : 0;
            int z = x + y + carry;
            result[k] = '0' + z % 2;
            carry = z / 2;
            --i;
            --j;
            --k;
        }
        while (!result.empty() and result.front() == '0') {
            result.erase(result.begin());
        }
        if (result.empty()) {
            result = "0";
        }
        return result;
    }
};

int main(void) {
	Solution solution;
	string a, b, answer, result;

	a = "1000";
	b = "1110101";
	answer = "1111101";
	result = solution.addBinary(a, b);
	assert(answer == result);

	a = "0";
	b = "0";
	answer = "0";
	result = solution.addBinary(a, b);
	assert(answer == result);

	a = "11";
	b = "1";
	answer = "100";
	result = solution.addBinary(a, b);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
