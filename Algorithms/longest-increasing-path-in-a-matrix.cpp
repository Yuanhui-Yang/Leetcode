// 329. Longest Increasing Path in a Matrix
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int M = matrix.size(), N = M == 0 ? 0 : matrix[0].size();
		vector<vector<int>> A(M, vector<int>(N, 0));
		array<int, 4> dx = {0, -1, 0, 1}, dy = {-1, 0, 1, 0};
		for (int x = 0; x < M; ++x) {
			for (int y = 0; y < N; ++y) {
				for (int i = 0; i < 4; ++i) {
					int nx = x + dx[i], ny = y + dy[i];
					if (nx >= 0 and nx < M and ny >= 0 and ny < N and matrix[x][y] < matrix[nx][ny]) {
						++A[nx][ny];
					}
				}
			}
		}
		int result = 0;
		list<array<int, 2>> curr;
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				if (A[i][j] == 0) {
					curr.push_back({i, j});
				}
			}
		}
		while (!curr.empty()) {
			++result;
			list<array<int, 2>> next;
			for (const auto & p : curr) {
				int x = p[0], y = p[1];
				for (int i = 0; i < 4; ++i) {
					int nx = x + dx[i], ny = y + dy[i];
					if (nx >= 0 and nx < M and ny >= 0 and ny < N and matrix[x][y] < matrix[nx][ny]) {
						if (--A[nx][ny] == 0) {
							next.push_back({nx, ny});
						}
					}
				}
			}
			curr = next;
		}
		return result;
	}
};

class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int M = matrix.size(), N = M == 0 ? 0 : matrix[0].size(), result = 0;
		vector<vector<int>> A(M, vector<int>(N, -1));
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				result = max(result, f(matrix, A, i, j));
			}
		}
		return result;
	}
private:
	int f(const vector<vector<int>>& matrix, vector<vector<int>> & A, int x, int y) {
		if (A[x][y] >= 0) {
			return A[x][y];
		}
		array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
		int result = 1, M = matrix.size(), N = M == 0 ? 0 : matrix[0].size();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 and nx < M and ny >= 0 and ny < N and matrix[x][y] < matrix[nx][ny]) {
				result = max(result, 1 + f(matrix, A, nx, ny));
			}
		}
		return A[x][y] = result;
	}
};