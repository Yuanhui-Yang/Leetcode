// 44. Wildcard Matching
// https://leetcode.com/problems/wildcard-matching/

/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		vector<vector<bool>> matrix(m + 1, vector<bool>(n + 1, false));
		matrix[0][0] = true;
		for (int i = 0; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (p[j - 1] == '*') {
					matrix[i][j] = matrix[i][j - 1] or (i > 0 and matrix[i - 1][j]);
				}
				else {
					matrix[i][j] = i > 0 and matrix[i - 1][j - 1] and (p[j - 1] == s[i - 1] or p[j - 1] == '?');
				}
			}
		}
		return matrix[m][n];
	}
};

int main(void) {
	Solution solution;
	string s, p;
	bool answer, result;

	s = "";
	p = "*";
	answer = true;
	result = solution.isMatch(s, p);
	assert(answer == result);

	s = "aa";
	p = "a";
	answer = false;
	result = solution.isMatch(s, p);
	assert(answer == result);

	s = "aa";
	p = "aa";
	answer = true;
	result = solution.isMatch(s, p);
	assert(answer == result);

	s = "aa";
	p = "aaa";
	answer = false;
	result = solution.isMatch(s, p);
	assert(answer == result);

	s = "aa";
	p = "*";
	answer = true;
	result = solution.isMatch(s, p);
	assert(answer == result);

	s = "aa";
	p = "a*";
	answer = true;
	result = solution.isMatch(s, p);
	assert(answer == result);

	s = "aa";
	p = "?*";
	answer = true;
	result = solution.isMatch(s, p);
	assert(answer == result);

	s = "aab";
	p = "c*a*b";
	answer = false;
	result = solution.isMatch(s, p);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}