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

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		int p = matrix.size(), q = p > 0 ? matrix.front().size() : 0, top = 0, bottom = p - 1, left = 0, right = q - 1, x = 0, y = 0, sz = p * q;
		for (int i = 0, mode = 0; i < sz; ++i) {
			result.push_back(matrix[x][y]);
			if (mode == 0) {
				if (++y > right) {
					++x;
					--y;
					++top;
					mode = 1;
				}
				continue;
			}
			if (mode == 1) {
				if (++x > bottom) {
					--x;
					--y;
					--right;
					mode = 2;
				}
				continue;
			}
			if (mode == 2) {
				if (--y < left) {
					--x;
					++y;
					--bottom;
					mode = 3;
				}
				continue;
			}
			if (mode == 3) {
				if (--x < top) {
					++x;
					++y;
					++left;
					mode = 0;
				}
				continue;
			}
		}
		return result;
	}
};