// 73. Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes/

/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		bool a = false, b = false;
		int m = matrix.size(), n = matrix.front().size();
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j]) {
					continue;
				}
				if (i == 0) {
					a = true;
				}
				if (j == 0) {
					b = true;
				}
				if (i > 0 and j > 0) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (matrix[0][j] == 0 or matrix[i][0] == 0) {
					matrix[i][j] = 0;
				}
			}
		}
		if (a) {
			for (int j = 0; j < n; ++j) {
				matrix[0][j] = 0;
			}
		}
		if (b) {
			for (int i = 0; i < m; ++i) {
				matrix[i][0] = 0;
			}
		}
	}
};

int main(void) {
	Solution solution;
	vector<vector<int>> matrix, answer;

	matrix = {{0, 0, 0, 5}, {4, 3, 1, 4}, {0, 1, 1, 4}, {1, 2, 1, 3}, {0, 0, 1, 1}};
	answer = {{0, 0, 0, 0}, {0, 0, 0, 4}, {0, 0, 0, 0}, {0, 0, 0, 3}, {0, 0, 0, 0}};
	solution.setZeroes(matrix);
	assert(answer == matrix);

	cout << "\nPassed All\n";
	return 0;
}