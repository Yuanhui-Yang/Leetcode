// 340. Longest Substring with At Most K Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		if (k <= 0) {
			return 0;
		}
		int n = s.size(), i = 0, j = 0, result = 0, h[256];
		memset(h, 0, sizeof(h));
		while (j < n) {
			while (j < n and (k > 0 or h[s[j] - 0] > 0)) {
				if (h[s[j++] - 0]++ == 0) {
					--k;
				}
			}
			if (result == 0 or j - i > result) {
				result = j - i;
			}
			while (k == 0) {
				if (--h[s[i++] - 0] == 0) {
					++k;
				}
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	string s;
	int k, answer, result;

	s = "nfhiexxjrtvpfhkrxcutexxcodfioburrtjefrgwrnqtyzelvtpvwdvvpsbudwtiryqzzy";
	k = 25;
	answer = 70;
	result = solution.lengthOfLongestSubstringKDistinct(s, k);
	assert(answer == result);

	s = "eceba";
	k = 2;
	answer = 3;
	result = solution.lengthOfLongestSubstringKDistinct(s, k);
	assert(answer == result);

	s = "a";
	k = 0;
	answer = 0;
	result = solution.lengthOfLongestSubstringKDistinct(s, k);
	assert(answer == result);

	s = "a";
	k = 2;
	answer = 1;
	result = solution.lengthOfLongestSubstringKDistinct(s, k);
	assert(answer == result);

	s = "aa";
	k = 1;
	answer = 2;
	result = solution.lengthOfLongestSubstringKDistinct(s, k);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}