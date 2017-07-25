// 308. Range Sum Query 2D - Mutable
// https://leetcode.com/problems/range-sum-query-2d-mutable/

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
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10
Note:
The matrix is only modifiable by the update function.
You may assume the number of calls to update and sumRegion function is distributed evenly.
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
				f(i + 1, j + 1, matrix[i][j]);
			}
		}
	}

	void update(int row, int col, int val) {
		f(row + 1, col + 1, val - h(row + 1, col + 1));
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return g(row2 + 1, col2 + 1) + g(row1, col1) - g(row2 + 1, col1) - g(row1, col2 + 1);
	}
private:
	vector<vector<int>> A;
	void f(int x, int y, int val) {
		int M = A.size(), N = M == 0 ? 0 : A[0].size();
		for (int i = x; i < M; i += i & (-i)) {
			for (int j = y; j < N; j += j & (-j)) {
				A[i][j] += val;
			}
		}
	}
	int g(int x, int y) {
		int result = 0;
		for (int i = x; i > 0; i -= i & (-i)) {
			for (int j = y; j > 0; j -= j & (-j)) {
				result += A[i][j];
			}
		}
		return result;
	}
	int h(int x, int y) {
		int result = A[x][y], lx = x - (x & (-x)), ly = y - (y & (-y));
		for (int i = x - 1; i > lx; i -= i & (-i)) {
			for (int j = y - 1; j > ly; j -= j & (-j)) {
				result += A[i][j];
			}
		}
		for (int i = x - 1; i > lx; i -= i & (-i)) {
			for (int j = y; j > ly; j -= j & (-j)) {
				result -= A[i][j];
			}
		}
		for (int i = x; i > lx; i -= i & (-i)) {
			for (int j = y - 1; j > ly; j -= j & (-j)) {
				result -= A[i][j];
			}
		}
		return result;
	}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */