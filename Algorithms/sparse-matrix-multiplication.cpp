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
		int P = A.size(), Q = P == 0 ? 0 : A[0].size(), R = B.size(), S = R == 0 ? 0 : B[0].size();
		if (Q != R) {
			return {};
		}
		vector<list<array<int, 2>>> X(P), Y(R);
		for (int i = 0; i < P; ++i) {
			for (int j = 0; j < Q; ++j) {
				int val = A[i][j];
				if (val) {
					X[i].push_back({j, val});
				}
			}
		}
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < S; ++j) {
				int val = B[i][j];
				if (val) {
					Y[i].push_back({j, val});
				}
			}
		}
		vector<vector<int>> result(P, vector<int>(S, 0));
		for (int i = 0; i < P; ++i) {
			for (const auto & j : X[i]) {
				for (const auto & k : Y[j[0]]) {
					result[i][k[0]] += j[1] * k[1];
				}
			}
		}
		return result;
	}
};

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