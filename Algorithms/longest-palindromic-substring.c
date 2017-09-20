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

char* longestPalindrome(char* s) {
	int sLen = strlen(s), tLen = 2 * sLen + 1, i = 0, j = 0, k = 0, x = 0, y = 0, z = 0, maxCenter = 0, maxLen = 0;
	int * A = malloc(tLen * sizeof(int));
	memset(A, 0, tLen * sizeof(char));
	char * t = malloc(tLen * sizeof(char));
	t[0] = '#';
	for (i = 0, j = 1; i < sLen; ++i) {
		t[j] = s[i];
		++j;
		t[j] = '#';
		++j;
	}
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
			A[i] = k - 1;
		}
		if (i + A[i] > x + y) {
			x = i;
			y = A[i];
		}
		if (A[i] > maxLen) {
			maxCenter = i;
			maxLen = A[i];
		}
	}
	char * result = malloc((maxLen + 1) * sizeof(char));
	result[maxLen] = '\0';
	for (i = maxCenter - maxLen, j = 0; i <= maxCenter + maxLen; ++i) {
		if (t[i] != '#') {
			result[j] = t[i];
			++j;
		}
	}
	return result;
}