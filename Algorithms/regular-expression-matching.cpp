// 10. Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/

/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		vector<vector<bool>> OPT(1 + m, vector<bool>(1 + n, false));
		OPT[0][0] = true;
		for (int i = 0; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (p[j - 1] == '*') {
					OPT[i][j] = j > 1 and (OPT[i][j - 2] or (i > 0 and OPT[i - 1][j] and (p[j - 2] == '.' or p[j - 2] == s[i - 1])));
				}
				else {
					OPT[i][j] = i > 0 and OPT[i - 1][j - 1] and (p[j - 1] == '.' or p[j - 1] == s[i - 1]);
				}
			}
		}
		return OPT[m][n];
	}
};

int main(void) {
	Solution solution;
	string s, p;
	bool answer, result;

	s = "abcd";
	p = "d*";
	answer = false;
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

	s = "aaa";
	p = "aa";
	answer = false;
	result = solution.isMatch(s, p);
	assert(answer == result);

	s = "aa";
	p = "a*";
	answer = true;
	result = solution.isMatch(s, p);
	assert(answer == result);

	s = "aa";
	p = ".*";
	answer = true;
	result = solution.isMatch(s, p);
	assert(answer == result);

	s = "ab";
	p = ".*";
	answer = true;
	result = solution.isMatch(s, p);
	assert(answer == result);

	s = "aab";
	p = "c*a*b";
	answer = true;
	result = solution.isMatch(s, p);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}