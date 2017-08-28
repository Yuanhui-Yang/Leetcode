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

class Solution {
public:
	string minWindow(string s, string t) {
		int sz1 = s.size(), sz2 = t.size(), i = 0, j = 0, cnt = 0;
		string result;
		array<int, 256> A, B;
		A.fill(0);
		B.fill(0);
		for (const auto & i : t) {
			++A[i];
		}
		while (j < sz1 or j - i > sz2) {
			if (j - i  <= sz2) {
				int y = s[j];
				if (B[y] < A[y]) {
					++cnt;
				}
				++B[y];
				++j;
			}
			else if (j == sz1) {
				int x = s[i];
				if (B[x] == A[x]) {
					--cnt;
				}
				--B[x];
				++i;
			}
			else if (cnt < sz2) {
				int y = s[j];
				if (B[y] < A[y]) {
					++cnt;
				}
				++B[y];
				++j;
			}
			else {
				int x = s[i];
				if (B[x] == A[x]) {
					--cnt;
				}
				--B[x];
				++i;
			}
			if (cnt == sz2) {
				if (result.empty() or j - i < result.size()) {
					result = s.substr(i, j - i);
				}
			}
		}
		return result;
	}
};