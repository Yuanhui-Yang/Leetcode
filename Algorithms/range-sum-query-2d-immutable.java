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

	public NumMatrix(int[][] matrix) {
		if (matrix == null || matrix.length == 0 || matrix[0] == null || matrix[0].length == 0) {
			return;
		}
		int X = matrix.length, Y = matrix[0].length, i = 0, j = 0, sum = 0;
		A = new int[X + 1][Y + 1];
		for (i = 1; i <= X; ++i) {
			sum = 0;
			for (j = 1; j <= Y; ++j) {
				sum += matrix[i - 1][j - 1];
				A[i][j] = A[i - 1][j] + sum;
			}
		}
	}
	
	public static int sumRegion(int row1, int col1, int row2, int col2) {
		return A[row2 + 1][col2 + 1] - A[row2 + 1][col1] - A[row1][col2 + 1] + A[row1][col1];
	}
	private static int[][] A = null;
	public static void main(String[] args) {
		int[][] matrix = null;
		matrix = new int[][] {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
		NumMatrix numMatrix = new NumMatrix(matrix);
		System.out.println(numMatrix.sumRegion(2, 1, 4, 3));
		System.out.println(numMatrix.sumRegion(1, 1, 2, 2));
		System.out.println(numMatrix.sumRegion(1, 2, 2, 4));
	}
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */