// 542. 01 Matrix
// https://leetcode.com/problems/01-matrix/

/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
*/

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <array>

using namespace std;

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		int X = matrix.size(), Y = X == 0 ? 0 : matrix[0].size(), i, j, k, l, m;
		if (X == 0 or Y == 0) {
			return {};
		}
		vector<vector<int>> result(X, vector<int>(Y, INT_MAX));
		array<int, 4> dx({0, -1, 0, 1}), dy({-1, 0, 1, 0});
		array<int, 2> p, q;
		queue<array<int, 2>> curr;
		for (i = 0; i < X; ++i) {
			for (j = 0; j < Y; ++j) {
				if (matrix[i][j] == 0) {
					curr.push({i, j});
					result[i][j] = 0;
				}
			}
		}
		while (!curr.empty()) {
			l = curr.size();
			while (l-- > 0) {
				p = curr.front();
				curr.pop();
				for (m = 0; m < 4; ++m) {
					q[0] = p[0] + dx[m];
					q[1] = p[1] + dy[m];
					if (q[0] >= 0 and q[0] < X and q[1] >= 0 and q[1] < Y and matrix[q[0]][q[1]] == 1 and result[p[0]][p[1]] + 1 < result[q[0]][q[1]]) {
						result[q[0]][q[1]] = result[p[0]][p[1]] + 1;
						curr.push(q);
					}
				}
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<vector<int>> matrix, result;
	
	matrix = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
	result = solution.updateMatrix(matrix);
	for (const auto & i : result) {
		for (const auto & j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	cout << '\n';
	
	matrix = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
	result = solution.updateMatrix(matrix);
	for (const auto & i : result) {
		for (const auto & j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	cout << '\n';

	return 0;
}