// 304. Range Sum Query 2D - Immutable
// https://leetcode.com/problems/range-sum-query-2d-immutable/

/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

class NumMatrix {
public:
	NumMatrix(vector<vector<int>> matrix) {
		int M = matrix.size(), N = M == 0 ? 0 : matrix[0].size();
		A.clear();
		A.resize(M + 1, vector<int>(N + 1, 0));
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				int val = matrix[i][j];
				for (int x = i + 1; x <= M; x += x & (-x)) {
					for (int y = j + 1; y <= N; y += y & (-y)) {
						A[x][y] += val;
					}
				}
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return f(row2 + 1, col2 + 1) + f(row1, col1) - f(row1, col2 + 1) - f(row2 + 1, col1);
	}
private:
	vector<vector<int>> A;
	int f(int x, int y) {
		int result = 0;
		for (int i = x; i > 0; i -= i & (-i)) {
			for (int j = y; j > 0; j -= j & (-j)) {
				result += A[i][j];
			}
		}
		return result;
	}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */