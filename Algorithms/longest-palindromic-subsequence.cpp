// 516. Longest Palindromic Subsequence
// https://leetcode.com/problems/longest-palindromic-subsequence/
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int longestPalindromeSubseq(string s) {
		if (s.empty()) {
			return 0;
		}
		vector<vector<int>> OPT(s.size(), vector<int>(s.size(), 1));
		for (size_t len = 2; len <= s.size(); len++) {
			for (size_t i = 0; i + len <= s.size(); i++) {
				size_t j = i + len - 1;
				if (s[i] == s[j]) {
					if (len == 2) {
						OPT[i][j] = 2;
					}
					else {
						OPT[i][j] = max(OPT[i][j], 2 + OPT[i + 1][j - 1]);
						OPT[i][j] = max(OPT[i][j], OPT[i][j - 1]);
						OPT[i][j] = max(OPT[i][j], OPT[i + 1][j]);
					}
				}
				else {
					if (len == 2) {
						OPT[i][j] = 1;
					}
					else {
						OPT[i][j] = max(OPT[i][j], OPT[i + 1][j - 1]);
						OPT[i][j] = max(OPT[i][j], OPT[i][j - 1]);
						OPT[i][j] = max(OPT[i][j], OPT[i + 1][j]);
					}
				}
			}
		}
		return OPT[0][s.size() - 1];
	}
};
int main(void) {
	Solution solution;
	string s;
	int result;

	s = "bbbab";
	result = solution.longestPalindromeSubseq(s);
	assert(4 == result);

	s = "cbbd";
	result = solution.longestPalindromeSubseq(s);
	assert(2 == result);

	cout << "\nPasssed All\n";
	return 0;
}