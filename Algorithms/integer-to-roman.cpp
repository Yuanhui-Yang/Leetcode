// 12. Integer to Roman
// https://leetcode.com/problems/integer-to-roman/

/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

I: 1
V: 5
X: 10
L: 50
C: 100
D: 500
M: 1000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<string> A = {"", "M", "MM", "MMM"};
        vector<string> B = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> C = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> D = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return A[num / 1000] + B[(num % 1000) / 100] + C[(num % 100) / 10] + D[num % 10];
    }
};

int main(void) {
	Solution solution;
	int num;
	string answer, result;

	num = 3999;
	answer = "MMMCMXCIX";
	result = solution.intToRoman(num);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
