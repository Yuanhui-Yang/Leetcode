// 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/

/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> h;
		h['I'] = 1;
		h['V'] = 5;
		h['X'] = 10;
		h['L'] = 50;
		h['C'] = 100;
		h['D'] = 500;
		h['M'] = 1000;
		int result = h[s.back()];
		for (int n = s.size(), i = n - 2; i >= 0; --i) {
			if (h[s[i]] < h[s[i + 1]]) {
				result -= h[s[i]];
			}
			else {
				result += h[s[i]];
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	string s;
	int answer, result;

	s = "MMMCMXCIX";
	answer = 3999;
	result = solution.romanToInt(s);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}