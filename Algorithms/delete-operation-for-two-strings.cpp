// 583. Delete Operation for Two Strings
// https://leetcode.com/problems/delete-operation-for-two-strings/

/*
Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		vector<vector<int>> OPT(2, vector<int>(n + 1, 0));
		for (int i = 0; i < m + 1; i++) {
			for (int j = 0; j < n + 1; j++) {
				int k = i % 2;
				if (i == 0 or j == 0) {
					OPT[k][j] = 0;
				}
				else if (word1[i - 1] == word2[j - 1]) {
					OPT[k][j] = OPT[1 - k][j - 1] + 1;
				}
				else {
					OPT[k][j] = max(OPT[1 - k][j], OPT[k][j - 1]);
				}
			}
		}
		return m + n - 2 * OPT[m % 2][n];
	}
};

int main(void) {
	Solution solution;
	string word1, word2;
	int result, answer;

	word1 = "sea";
	word2 = "eat";
	answer = 2;
	result = solution.minDistance(word1, word2);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
