// 551. Student Attendance Record I
// https://leetcode.com/problems/student-attendance-record-i/

/*
You are given a string representing an attendance record for a student. The record only contains the following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False
*/

class Solution {
public:
	bool checkRecord(string s) {
		for (int sz = s.size(), i = 0, A = -1; i < sz; ++i) {
			if (s[i] == 'P') {
				continue;
			}
			if (s[i] == 'A') {
				if (A == -1) {
					A = i;
					continue;
				}
				return false;
			}
			int cnt = 1;
			while (i + 1 < sz and s[i + 1] == 'L') {
				++i;
				++cnt;
			}
			if (cnt > 2) {
				return false;
			}
		}
		return true;
	}
};