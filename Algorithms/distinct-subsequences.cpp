// 115. Distinct Subsequences
// https://leetcode.com/problems/distinct-subsequences/

/*
Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

class Solution {
public:
	int numDistinct(string s, string t) {
		int m = s.size(), n = t.size();
		vector<vector<int>> M(2, vector<int>(n + 1, 0));
		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= n and j <= i; ++j) {
				int x = i % 2, y = 1 - x;
				if (j == 0) {
					M[x][j] = 1;
					continue;
				}
				if (i == 0) {
					M[x][j] = 0;
					continue;
				}
				if (i == j) {
					M[x][j] = s.substr(0, i) == t.substr(0, j);
					continue;
				}
				if (s[i - 1] == t[j - 1]) {
					M[x][j] = M[y][j - 1] + M[y][j];
				}
				else {
					M[x][j] = M[y][j];
				}
			}
		}
		return M[m % 2][n];
	}
};