// 311. Sparse Matrix Multiplication
// https://leetcode.com/problems/sparse-matrix-multiplication/

/*
Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


	 |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
				  | 0 0 1 |
*/

class Solution {
public:
	vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
		vector<array<int, 3>> P, Q;
		for (int M = A.size(), i = 0; i < M; ++i) {
			for (int N = A[i].size(), j = 0; j < N; ++j) {
				int val = A[i][j];
				if (val) {
					P.push_back({i, j, val});
				}
			}
		}
		for (int M = B.size(), i = 0; i < M; ++i) {
			for (int N = B[i].size(), j = 0; j < N; ++j) {
				int val = B[i][j];
				if (val) {
					Q.push_back({i, j, val});
				}
			}
		}
		int M = A.size(), N = B.empty() ? 0 : B[0].size();
		vector<vector<int>> result(M, vector<int>(N, 0));
		for (const auto & x : P) {
			for (const auto & y : Q) {
				if (x[1] == y[0]) {
					result[x[0]][y[1]] += x[2] * y[2];
				}
			}
		}
		return result;
	}
};