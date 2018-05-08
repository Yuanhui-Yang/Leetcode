// 168. Excel Sheet Column Title
// https://leetcode.com/problems/excel-sheet-column-title/

/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

	1 -> A
	2 -> B
	3 -> C
	...
	26 -> Z
	27 -> AA
	28 -> AB 
*/

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n > 0) {
            int id = (n - 1) % 26;
            char ch = id + 'A';
            result.push_back(ch);
            n = (n - 1) / 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
