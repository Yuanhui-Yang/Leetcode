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
        int sz1 = s1.size(), sz2 = s2.size(), sz3 = s3.size();
        if (sz1 + sz2 != sz3)
        {
            return false;
        }
        vector<vector<bool>> A(sz1 + 1, vector<bool>(sz2 + 1, false));
        for (int i = 0; i <= sz1; ++i)
        {
            for (int j = 0; j <= sz2; ++j)
            {
                if (i == 0 and j == 0)
                {
                    A[i][j] = true;
                }
                else if (i == 0)
                {
                    A[i][j] = A[i][j - 1] and s2[j - 1] == s3[i + j - 1];
                }
                else if (j == 0)
                {
                    A[i][j] = A[i - 1][j] and s1[i - 1] == s3[i + j - 1];
                }
                else
                {
                    A[i][j] = (A[i][j - 1] and s2[j - 1] == s3[i + j - 1]) or (A[i - 1][j] and s1[i - 1] == s3[i + j - 1]);
                }
            }
        }
        return A[sz1][sz2];
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
