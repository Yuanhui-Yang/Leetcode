// 97. Interleaving String
// https://leetcode.com/problems/interleaving-string/

/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size()) {
			return false;
		}
		int a = s1.size(), b = s2.size();
		vector<vector<bool>> M(a + 1, vector<bool>(b + 1, false));
		for (int i = 0; i <= a; ++i) {
			for (int j = 0; j <= b; ++j) {
				if (i == 0 and j == 0) {
					M[i][j] = true;
					continue;
				}
				if (i == 0) {
					M[i][j] = s2.substr(0, j) == s3.substr(0, j);
					continue;
				}
				if (j == 0) {
					M[i][j] = s1.substr(0, i) == s3.substr(0, i);
					continue;
				}
				M[i][j] = M[i][j] or (M[i - 1][j] and s1[i - 1] == s3[i + j - 1]);
				M[i][j] = M[i][j] or (M[i][j - 1] and s2[j - 1] == s3[i + j - 1]);
			}
		}
		return M[a][b];
	}
};

int main(void) {
	Solution solution;
	string s1, s2, s3;
	bool answer, result;

	s1 = "aabcc";
	s2 = "dbbca";
	s3 = "aadbbcbcac";
	answer = true;
	result = solution.isInterleave(s1, s2, s3);
	assert(answer == result);

	s1 = "aabcc";
	s2 = "dbbca";
	s3 = "aadbbbaccc";
	answer = false;
	result = solution.isInterleave(s1, s2, s3);
	assert(answer == result);

	s1 = "ab";
	s2 = "bc";
	s3 = "bbac";
	answer = false;
	result = solution.isInterleave(s1, s2, s3);
	assert(answer == result);

	s1 = "aa";
	s2 = "ab";
	s3 = "aaba";
	answer = true;
	result = solution.isInterleave(s1, s2, s3);
	assert(answer == result);

	s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
	s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
	s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
	answer = false;
	result = solution.isInterleave(s1, s2, s3);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}