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

class Solution {
public:
	int minDistance(string word1, string word2) {
		int M = word1.size(), N = word2.size();
		if (M < N) {
			return minDistance(word2, word1);
		}
		array<vector<int>, 2> A;
		A[0].resize(N + 1, 0);
		A[1].resize(N + 1, 0);
		for (int i = 0; i <= M; ++i) {
			int x = i % 2, y = 1 - x;
			for (int j = 0; j <= N; ++j) {
				if (i == 0) {
					A[x][j] = j;
				}
				else if (j == 0) {
					A[x][j] = i;
				}
				else if (word1[i - 1] == word2[j - 1]) {
					A[x][j] = A[y][j - 1];
				}
				else {
					A[x][j] = min(A[x][j - 1], A[y][j]) + 1;
				}
			}
		}
		return A[M % 2][N];
	}
};

class Solution {
public:
	int minDistance(string word1, string word2) {
		int M = word1.size(), N = word2.size();
		vector<vector<int>> A(M + 1, vector<int>(N + 1, 0));
		for (int i = 0; i <= M; ++i) {
			A[i][0] = i;
		}
		for (int j = 0; j <= N; ++j) {
			A[0][j] = j;
		}
		for (int i = 1; i <= M; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (word1[i - 1] == word2[j - 1]) {
					A[i][j] = A[i - 1][j - 1];
				}
				else {
					A[i][j] = min(A[i - 1][j], A[i][j - 1]) + 1;
				}
			}
		}
		return A[M][N];
	}
};