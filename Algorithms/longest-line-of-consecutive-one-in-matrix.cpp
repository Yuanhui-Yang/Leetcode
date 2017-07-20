// 562. Longest Line of Consecutive One in Matrix
// https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/

/*
Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.

Example:
Input:
[[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]
Output: 3
Hint: The number of elements in the given matrix will not exceed 10,000.
*/

class Solution {
public:
	int longestLine(vector<vector<int>>& M) {
		int X = M.size(), Y = X == 0 ? 0 : M[0].size(), result = 0;
		array<array<vector<int>, 2>, 4> A;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 2; ++j) {
				A[i][j].resize(Y, 0);
			}
		}
		for (int i = 0; i < X; ++i) {
			for (int j = 0; j < Y; ++j) {
				int x = i % 2, y = 1 - x;
				if (M[i][j] == 0) {
					A[0][x][j] = 0;
					A[1][x][j] = 0;
					A[2][x][j] = 0;
				}
				else if (i == 0 and j == 0) {
					A[0][x][j] = 1;
					A[1][x][j] = 1;
					A[2][x][j] = 1;
				}
				else if (i == 0) {
					A[0][x][j] = 1;
					A[1][x][j] = 1 + A[1][x][j - 1];
					A[2][x][j] = 1;
				}
				else if (j == 0) {
					A[0][x][j] = 1 + A[0][y][j];
					A[1][x][j] = 1;
					A[2][x][j] = 1;
				}
				else {
					A[0][x][j] = 1 + A[0][y][j];
					A[1][x][j] = 1 + A[1][x][j - 1];
					A[2][x][j] = 1 + A[2][y][j - 1];
				}
				result = max(result, A[0][x][j]);
				result = max(result, A[1][x][j]);
				result = max(result, A[2][x][j]);
			}
		}
		for (int i = 0; i < X; ++i) {
			for (int j = Y - 1; j >= 0; --j) {
				int x = i % 2, y = 1 - x;
				if (M[i][j] == 0) {
					A[3][x][j] = 0;
				}
				else if (i == 0) {
					A[3][x][j] = 1;
				}
				else if (j == Y - 1) {
					A[3][x][j] = 1;
				}
				else {
					A[3][x][j] = 1 + A[3][y][j + 1];
				}
				result = max(result, A[3][x][j]);
			}
		}
		return result;
	}
};

class Solution {
public:
	int longestLine(vector<vector<int>>& M) {
		int X = M.size(), Y = X == 0 ? 0 : M[0].size(), result = 0;
		array<vector<vector<int>>, 4> A;
		for (int i = 0; i < 4; ++i) {
			A[i].resize(X, vector<int>(Y, 0));
		}
		for (int i = 0; i < X; ++i) {
			for (int j = 0; j < Y; ++j) {
				if (M[i][j] == 0) {
					continue;
				}
				if (i == 0 and j == 0) {
					A[0][i][j] = 1;
					A[1][i][j] = 1;
					A[2][i][j] = 1;
				}
				else if (i == 0) {
					A[0][i][j] = 1;
					A[1][i][j] = 1 + A[1][i][j - 1];
					A[2][i][j] = 1;
				}
				else if (j == 0) {
					A[0][i][j] = 1 + A[0][i - 1][j];
					A[1][i][j] = 1;
					A[2][i][j] = 1;
				}
				else {
					A[0][i][j] = 1 + A[0][i - 1][j];
					A[1][i][j] = 1 + A[1][i][j - 1];
					A[2][i][j] = 1 + A[2][i - 1][j - 1];
				}
				result = max(result, A[0][i][j]);
				result = max(result, A[1][i][j]);
				result = max(result, A[2][i][j]);
			}
		}
		for (int i = 0; i < X; ++i) {
			for (int j = Y - 1; j >= 0; --j) {
				if (M[i][j] == 0) {
					continue;
				}
				if (i == 0) {
					A[3][i][j] = 1;
				}
				else if (j == Y - 1) {
					A[3][i][j] = 1;
				}
				else {
					A[3][i][j] = 1 + A[3][i - 1][j + 1];
				}
				result = max(result, A[3][i][j]);
			}
		}
		return result;
	}
};