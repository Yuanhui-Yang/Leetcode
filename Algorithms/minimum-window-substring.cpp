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
		if (s.empty() or t.empty()) {
			return 0;
		}
		int m = s.size(), x[256];
		memset(x, 0, sizeof(x));
		for (const auto &ch : t) {
			int d = ch - 0;
			++x[d];
		}
		vector<list<int>> y(256);
		string result;
		for (int i = -1, j = 0; j < m; ++j) {
			char ch = s[j];
			int d = ch - 0;
			if (!x[d]) {
				continue;
			}
			y[d].push_back(j);
			if (!f(x, y)) {
				continue;
			}
			while (i + 1 < j and (!x[s[i + 1] - 0] or x[s[i + 1] - 0] < int(y[s[i + 1] - 0].size()))) {
				if (!y[s[i + 1] - 0].empty()) {
					y[s[i + 1] - 0].pop_front();   
				}
				++i;
			}
			if (result.empty() or (j - i) < int(result.size())) {
				result = s.substr(i + 1, j - i);
			}
		}
		return result;
	}
private:
	bool f(int *x, vector<list<int>>& y) {
		int i = 0;
		while (i < 256 and x[i] <= int(y[i].size())) {
			++i;
		}
		return i == 256;
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