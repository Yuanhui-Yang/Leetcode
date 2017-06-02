// 6. ZigZag Conversion
// https://leetcode.com/problems/zigzag-conversion/

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows <= 0) {
			return "";
		}
		if (numRows == 1) {
			return s;
		}
		vector<string> v(numRows);
		for (int i = 0, j = 0, k = 0, n = s.size(); i < n; ++i) {
			v[j].push_back(s[i]);
			if (k % 2 == 0) {
				if (j + 1 < numRows) {
					++j;
				}
				else {
					--j;
					++k;
				}
			}
			else {
				if (j > 0) {
					--j;
				}
				else {
					++j;
					++k;
				}
			}
		}
		return accumulate(begin(v), end(v), string(""));;
	}
};

int main(void) {
	Solution solution;
	string s, answer, result;
	int numRows;

	s = "AB";
	numRows = 1;
	answer = "AB";
	result = solution.convert(s, numRows);
	assert(answer == result);

	s = "PAYPALISHIRING";
	numRows = 3;
	answer = "PAHNAPLSIIGYIR";
	result = solution.convert(s, numRows);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}