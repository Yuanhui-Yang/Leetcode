// 72. Edit Distance
// https://leetcode.com/problems/edit-distance/

/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		vector<vector<int>> OPT(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= n; ++j) {
				if (i == 0 or j == 0) {
					OPT[i][j] = i + j;
					continue;
				}
				if (word1[i - 1] == word2[j - 1]) {
					OPT[i][j] = OPT[i - 1][j - 1];
					continue;
				}
				OPT[i][j] = 1 + OPT[i - 1][j - 1];
				OPT[i][j] = min(OPT[i][j], 1 + OPT[i - 1][j]);
				OPT[i][j] = min(OPT[i][j], 1 + OPT[i][j - 1]);
			}
		}
		return OPT[m][n];
	}
};

int main(void) {
	Solution solution;

	string word1, word2;
	int answer, result;

	word1 = "";
	word2 = "";
	answer = 0;
	result = solution.minDistance(word1, word2);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}