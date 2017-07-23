// 459. Repeated Substring Pattern
// https://leetcode.com/problems/repeated-substring-pattern/

/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		if (s.size() <= 1) {
			return false;
		}
		int sz = s.size(), i = 0, j = -1;
		vector<int> A(sz + 1);
		A[0] = -1;
		while (i < sz) {
			if (j == -1 or s[i] == s[j]) {
				A[++i] = ++j;
			}
			else {
				j = A[j];
			}
		}
		return 0 < A[sz] and A[sz] < sz and sz % (sz - A[sz]) == 0;
	}
};