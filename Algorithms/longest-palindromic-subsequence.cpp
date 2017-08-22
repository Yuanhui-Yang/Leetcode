// 516. Longest Palindromic Subsequence
// https://leetcode.com/problems/longest-palindromic-subsequence/

/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
*/

class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int sz = s.size();
		if (sz == 0) {
			return 0;
		}
		vector<vector<int>> A(sz, vector<int>(sz, 0));
		for (int len = 1; len <= sz; ++len) {
			for (int i = 0; i + len <= sz; ++i) {
				int j = i + len - 1;
				if (len == 1) {
					A[i][j] = 1;
				}
				else if (s[i] == s[j]) {
					A[i][j] = 2 + A[i + 1][j - 1];
				}
				else {
					A[i][j] = max(A[i + 1][j], A[i][j - 1]);
				}
			}
		}
		return A[0][sz - 1];
	}
};