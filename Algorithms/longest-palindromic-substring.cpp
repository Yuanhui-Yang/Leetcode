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
public:
	string longestPalindrome(string s) {
		string t;
		t.push_back('#');
		for (const auto & i : s) {
			t.push_back(i);
			t.push_back('#');
		}
		int len = t.size(), i = 0, j = 0, k = 0, x = 0, y = 0, z = 0, maxCenter = 0, maxLen = 0;
		vector<int> A(len, 0);
		for (i = 1; i < len; ++i) {
			j = 2 * x - i;
			z = 2 * x - y;
			if (j - A[j] > z) {
				A[i] = A[j];
			}
			else {
				k = 0;
				while (i - k >= 0 and i + k < len and t[i - k] == t[i + k]) {
					++k;
				}
				A[i] = --k;
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
		return s.substr((maxCenter - maxLen) / 2, maxLen);
	}
};