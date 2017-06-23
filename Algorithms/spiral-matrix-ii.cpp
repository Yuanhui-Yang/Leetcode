// 59. Spiral Matrix II
// https://leetcode.com/problems/spiral-matrix-ii/

/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		int i = 0, j = 0, l = n * n, top = 0, bottom = n - 1, left = 0, right = n - 1, mode = 0;
		vector<vector<int>> result(n, vector<int>(n, 0));
		for (int k = 1; k <= l; ++k) {
			result[i][j] = k;
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
	int n;
	vector<vector<int>> answer, result;

	n = 3;
	answer = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
	result = solution.generateMatrix(n);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}