// 54. Spiral Matrix
// https://leetcode.com/problems/spiral-matrix/

/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty() or matrix.front().empty()) {
			return {};
		}
		int m = matrix.size(), n = matrix.front().size(), top = 0, bottom = m - 1, left = 0, right = n - 1, i = 0, j = 0, k = m * n, mode = 0;
		vector<int> result;
		while (k-- > 0) {
			result.push_back(matrix[i][j]);
			if (mode == 0) {
				if (++j > right) {
					++i;
					--j;
					++top;
					mode = 1;
				}
				continue;
			}
			if (mode == 1) {
				if (++i > bottom) {
					--i;
					--j;
					--right;
					mode = 2;
				}
				continue;
			}
			if (mode == 2) {
				if (--j < left) {
					--i;
					++j;
					--bottom;
					mode = 3;
				}
				continue;
			}
			if (mode == 3) {
				if (--i < top) {
					++i;
					++j;
					++left;
					mode = 0;
				}
				continue;
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<vector<int>> matrix;
	vector<int> answer, result;

	matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	answer = {1, 2, 3, 6, 9, 8, 7, 4, 5};
	result = solution.spiralOrder(matrix);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}