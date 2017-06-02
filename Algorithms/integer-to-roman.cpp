// 12. Integer to Roman
// https://leetcode.com/problems/integer-to-roman/

/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string M[] = {"", "M", "MM", "MMM"};
		string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
		string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
		string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
		return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
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