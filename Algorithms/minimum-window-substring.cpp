// 76. Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/

/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		int m = s.size(), n = t.size(), i = 0, j = 0, h[256];
		if (m == 0 or n == 0 or m < n) {
			return "";
		}
		memset(h, 0, sizeof(h));
		for (const auto &i : t) {
			++h[i - 0];
		}
		string result;
		while (j < m) {
			while (j < m and n > 0) {
				if (h[s[j++] - 0]-- > 0) {
					--n;
				}
			}
			while (n == 0) {
				if (result.empty() or j - i < int(result.size())) {
					result = s.substr(i, j - i);
				}
				if (i < j and h[s[i++] - 0]++ == 0) {
					++n;
				}
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	string s, t, answer, result;

	s = "aaaaaaaaaaaabbbbbcdd";
	t = "abcdd";
	answer = "abbbbbcdd";
	result = solution.minWindow(s, t);
	assert(answer == result);

	s = "ab";
	t = "b";
	answer = "b";
	result = solution.minWindow(s, t);
	assert(answer == result);

	s = "ADOBECODEBANC";
	t = "ABC";
	answer = "BANC";
	result = solution.minWindow(s, t);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}