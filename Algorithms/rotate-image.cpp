// 48. Rotate Image
// https://leetcode.com/problems/rotate-image/

/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.empty()) {
			return; 
		}
		int n = matrix.size(), a = n / 2, b = (n + 1) / 2;
		for (int i = 0; i < a; ++i) {
			for (int j = 0; j < b; ++j) {
				swap(matrix[i][j], matrix[j][n - 1 - i]);
				swap(matrix[n - 1 - i][n - 1 - j], matrix[n - 1 - j][i]);
			}
		}
		for (int i = 0; i < a; ++i) {
			for (int j = 0; j < b; ++j) {
				swap(matrix[i][j], matrix[n - 1 - i][n - 1 - j]);
			}
		}
	}
};

int main(void) {
	Solution solution;
	vector<vector<int>> matrix, answer;

	matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	answer = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
	solution.rotate(matrix);
	assert(answer == matrix);

	matrix = {{1, 2}, {3, 4}};
	answer = {{3, 1}, {4, 2}};
	solution.rotate(matrix);
	assert(answer == matrix);

	cout << "\nPassed All\n";
	return 0;
}