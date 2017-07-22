// 434. Number of Segments in a String
// https://leetcode.com/problems/number-of-segments-in-a-string/

/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
*/

class Solution {
public:
	int countSegments(string s) {
		int result = 0, sz = s.size(), i = 0;
		while (i < sz) {
			if (s[i] == ' ') {
				++i;
				continue;
			}
			++result;
			while (i < sz and s[i] != ' ') {
				++i;
			}
		}
		return result;
	}
};