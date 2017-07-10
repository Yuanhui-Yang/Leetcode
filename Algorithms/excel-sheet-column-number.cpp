// 171. Excel Sheet Column Number
// https://leetcode.com/problems/excel-sheet-column-number/

/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

	A -> 1
	B -> 2
	C -> 3
	...
	Z -> 26
	AA -> 27
	AB -> 28 
*/

class Solution {
public:
	int titleToNumber(string s) {
		int result = 0, base = 26;
		for (const auto & i : s) {
			result = base * result + (i - 'A' + 1);
		}
		return result;
	}
};