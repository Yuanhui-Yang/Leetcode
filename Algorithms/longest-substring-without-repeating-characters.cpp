// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size(), i = 0, j = 0, result = 0, h[256];
		memset(h, 0, sizeof(h));
		while (j < n) {
			while (j < n and !h[s[j]]) {
				++h[s[j]];
				++j;
			}
			result = max(result, j - i);
			if (i < j) {
				--h[s[i]];
				++i;
			}
		}
		return result;
	}
};