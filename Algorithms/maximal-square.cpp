// 221. Maximal Square
// https://leetcode.com/problems/maximal-square/

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
*/

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int result = 0, p = matrix.size(), q = p > 0 ? matrix.front().size() : 0;
		vector<vector<int>> A(2, vector<int>(q, 0));
		for (int i = 0, j = 0; j < q; ++j) {
			if (matrix[i][j] == '1') {
				A[i % 2][j] = 1;
				result = 1;
			}
			else {
				A[i % 2][j] = 0;
			}
		}
		for (int i = 1; i < p; ++i) {
			int x = i % 2, y = 1 - x;
			A[x][0] = matrix[i][0] == '1';
			result = max(result, A[x][0]);
			for (int j = 1; j < q; ++j) {
				if (matrix[i][j] == '1') {
					A[x][j] = 1 + min(A[y][j - 1], min(A[x][j - 1], A[y][j]));
					result = max(result, A[x][j]);
				}
				else {
					A[x][j] = 0;
				}
			}
		}
		return result * result;
	}
};

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int result = 0, p = matrix.size(), q = p > 0 ? matrix.front().size() : 0;
		vector<vector<int>> A(p, vector<int>(q, 0));
		for (int i = 0, j = 0; i < p; ++i) {
			if (matrix[i][j] == '1') {
				A[i][j] = 1;
				result = 1;
			}
		}
		for (int i = 0, j = 0; j < q; ++j) {
			if (matrix[i][j] == '1') {
				A[i][j] = 1;
				result = 1;
			}
		}
		for (int i = 1; i < p; ++i) {
			for (int j = 1; j < q; ++j) {
				if (matrix[i][j] != '1') {
					continue;
				}
				A[i][j] = 1 + min(A[i - 1][j - 1], min(A[i - 1][j], A[i][j - 1]));
				result = max(result, A[i][j]);
			}
		}
		return result * result;
	}
};