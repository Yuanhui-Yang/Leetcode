// 74. Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() or matrix.front().empty()) {
			return false;
		}
		int m = matrix.size(), n = matrix.front().size(), i = 0, j = m;
		while (i < j) {
			int mid = i + (j - i) / 2;
			if (matrix[mid][0] <= target) {
				i = mid + 1;
			}
			else {
				j = mid;
			}
		}
		if (i == 0) {
			return false;
		}
		int r = i - 1;
		i = 0;
		j = n;
		while (i < j) {
			int mid = i + (j - i) / 2;
			if (matrix[r][mid] < target) {
				i = mid + 1;
			}
			else {
				j = mid;
			}
		}
		return i < n and matrix[r][i] == target;
	}
};

int main(void) {
	Solution solution;
	vector<vector<int>> matrix;
	int target;
	bool answer, result;

	matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
	target = 3;
	answer = true;
	result = solution.searchMatrix(matrix, target);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}