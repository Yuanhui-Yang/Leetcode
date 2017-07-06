// 132. Palindrome Partitioning II
// https://leetcode.com/problems/palindrome-partitioning-ii/

/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

class Solution {
public:
	int minCut(string s) {
		int n = s.size();
		vector<int> vec(n + 1, 0);
		iota(begin(vec), end(vec), -1);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; i - j >= 0 and i + j < n and s[i - j] == s[i + j]; ++j) {
				vec[i + j + 1] = min(vec[i + j + 1], 1 + vec[i - j]);
			}
			for (int j = 1; i + 1 - j >= 0 and i + j < n and s[i + 1 - j] == s[i + j]; ++j) {
				vec[i + j + 1] = min(vec[i + j + 1], 1 + vec[i + 1 - j]);
			}
		}
		return vec[n];
	}
};