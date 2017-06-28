// 161. One Edit Distance
// https://leetcode.com/problems/one-edit-distance/

/*
Given two strings S and T, determine if they are both one edit distance apart.
*/

class Solution {
public:
	bool isOneEditDistance(string s, string t) {
		int m = s.size(), n = t.size();
		if (m > n) {
			return isOneEditDistance(t, s);
		}
		int i = 0, j = m != n;
		while (i < m and s[i] == t[i]) {
			++i;
		}
		++i;
		while (i - j < m and i < n and s[i - j] == t[i]) {
			++i;
		}
		return i == n;
	}
};