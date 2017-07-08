// 159. Longest Substring with At Most Two Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

/*
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.
*/

class Solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s) {
		int h[256], n = s.size(), i = 0, j = 0, result = 0, cnt = 0;
		memset(h, 0, sizeof(h));
		while (j < n) {
			while (j < n and cnt < 2) {
				if (!h[s[j]]) {
					++cnt;
				}
				++h[s[j]];
				++j;
			}
			while (j < n and h[s[j]] > 0) {
				++h[s[j]];
				++j;
			}
			result = max(result, j - i);
			while (i < j and cnt >= 2) {
				--h[s[i] - 0];
				if (!h[s[i]]) {
					--cnt;
				}
				++i;
			}
		}
		return result;
	}
};