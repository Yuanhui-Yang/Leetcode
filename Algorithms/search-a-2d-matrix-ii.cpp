// 240. Search a 2D Matrix II
// https://leetcode.com/problems/search-a-2d-matrix-ii/

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int M = matrix.size(), N = M == 0 ? 0 : matrix[0].size(), i = 0, j = N - 1;
		if (M == 0 or N == 0 or target < matrix[0][0] or target > matrix[M - 1][N - 1]) {
			return false;
		}
		while (i >= 0 and i < M and j >= 0 and j < N) {
			int val = matrix[i][j];
			if (val == target) {
				return true;
			}
			if (val < target) {
				++i;
			}
			else {
				--j;
			}
		}
		return false;
	}
};