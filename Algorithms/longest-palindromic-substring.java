// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/

/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

class Solution {
	public String longestPalindrome(String s) {
		int len = s.length(), i, j, k, x = 0, y = 0;
		boolean[][] DP = new boolean[len][len];
		for (i = 0; i < len; ++i) {
			for (j = 0; j < len; ++j) {
				DP[i][j] = false;
			}
		}
		for (i = 1; i <= len; ++i) {
			for (j = 0; j + i <= len; ++j) {
				k = i + j - 1;
				if (i == 1) {
					DP[j][k] = true;
				}
				else if (i == 2) {
					DP[j][k] = s.charAt(j) == s.charAt(k);
				}
				else {
					DP[j][k] = s.charAt(j) == s.charAt(k) && DP[j + 1][k - 1];
				}
				if (DP[j][k] && i > y - x) {
					x = j;
					y = k;
				}
			}
		}
		return s.substring(x, y + 1);
	}
}