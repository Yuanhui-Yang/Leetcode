// 340. Longest Substring with At Most K Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.
*/

class Solution {
public:
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		if (k <= 0) {
			return 0;
		}
		int i = 0, j = 0, n = s.size(), result = 0, h[256], cnt = 0;
		memset(h, 0, sizeof(h));
		while (j < n) {
			while (j < n and cnt < k) {
				if (!h[s[j]]) {
					++cnt;
				}
				++h[s[j]];
				++j;
			}
			while (j < n and h[s[j]]) {
				++h[s[j]];
				++j;
			}
			result = max(result, j - i);
			while (i < j and cnt >= k) {
				--h[s[i]];
				if (!h[s[i]]) {
					--cnt;
				}
				++i;
			}
		}
		return result;
	}
};