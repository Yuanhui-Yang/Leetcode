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
		if (s == null || s.length() <= 1) {
			return s;
		}
		int i = 0, j = 0, k = 0, x = 0, y = 0, z = 0, sLen = s.length(), tLen = 2 * sLen + 1, maxCenter = 0, maxLen = 0;
		char[] t = new char[tLen];
		t[0] = '#';
		for (i = 0, j = 1; i < sLen; ++i) {
			t[j] = s.charAt(i);
			++j;
			t[j] = '#';
			++j;
		}
		int[] A = new int[tLen];
		A[0] = 0;
		for (i = 1; i < tLen; ++i) {
			j = 2 * x - i;
			z = x - y;
			if (j >= 0 && j - A[j] > z) {
				A[i] = A[j];
			}
			else {
				k = 0;
				while (i - k >= 0 && i + k < tLen && t[i - k] == t[i + k]) {
					++k;
				}
				A[i] = --k;
			}
			if (i + A[i] > x + y) {
				x = i;
				y = A[i];
			}
			if (A[i] > maxLen) {
				maxCenter = x;
				maxLen = A[i];
			}
		}
		return s.substring((maxCenter - maxLen) / 2, (maxCenter + maxLen) / 2);
	}
}

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