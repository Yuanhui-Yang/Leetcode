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
		int n = t.size(), x = 0, y = 0, a = 0, b = 0;
		vector<int> vec(n, 0);
		for (int i = 0; i < n; ++i) {
			int c = a - b, d = a + b;
			int j = 2 * x - i;
			if (j > c and j - vec[j] > c) {
				vec[i] = vec[j];
			}
			else {
				int e = 0;
				while (i - e >= 0 and i + e < n and t[i - e] == t[i + e]) {
					++e;
				}
				vec[i] = --e;
			}
			if (y < vec[i]) {
				x = i;
				y = vec[i];
			}
			if (a + b < i + vec[i]) {
				a = i;
				b = vec[i];
			}
		}
		string result;
		for (int i = x - y + 1; i < x + y; i += 2) {
			result.push_back(t[i]);
		}
		return result;
	}
};