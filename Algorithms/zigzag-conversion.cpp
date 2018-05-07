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
        vector<string> A(numRows);
        int sz = s.size(), i = 0;
        while (i < sz) {
            for (int j = 0; j <= numRows - 1 and i < sz; ++j, ++i) {
                A[j].push_back(s[i]);
            }
            for (int j = numRows - 2; j >= 1 and i < sz; --j, ++i) {
                A[j].push_back(s[i]);
            }
        }
        return accumulate(A.begin(), A.end(), string());
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
