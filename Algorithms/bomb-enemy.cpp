// 361. Bomb Enemy
// https://leetcode.com/problems/bomb-enemy/

/*
Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.

Example:
For the given grid

0 E 0 0
E 0 W E
0 E 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxKilledEnemies(vector<vector<char>>& grid) {
		int X = grid.size(), Y = X == 0 ? 0 : grid[0].size(), result = 0, i = 0, j = 0, curr = 0;
		if (X == 0 or Y == 0) {
			return 0;
		}
		vector<vector<int>> A(X, vector<int>(Y, 0)), B(A), C(A), D(A);
		for (i = 0; i < X; ++i) {
			for (j = 0; j < Y; ++j) {
				if (grid[i][j] == 'W') {
					A[i][j] = 0;
				}
				else if (grid[i][j] == '0') {
					if (j == 0) {
						A[i][j] = 0;
					}
					else {
						A[i][j] = A[i][j - 1];
					}
				}
				else {
					if (j == 0) {
						A[i][j] = 1;
					}
					else {
						A[i][j] = 1 + A[i][j - 1];
					}
				}
			}
		}
		for (i = 0; i < X; ++i) {
			for (j = Y - 1; j >= 0; --j) {
				if (grid[i][j] == 'W') {
					B[i][j] = 0;
				}
				else if (grid[i][j] == '0') {
					if (j == Y - 1) {
						B[i][j] = 0;
					}
					else {
						B[i][j] = B[i][j + 1];
					}
				}
				else {
					if (j == Y - 1) {
						B[i][j] = 1;
					}
					else {
						B[i][j] = 1 + B[i][j + 1];
					}
				}
			}
		}
		for (j = 0; j < Y; ++j) {
			for (i = 0; i < X; ++i) {
				if (grid[i][j] == 'W') {
					C[i][j] = 0;
				}
				else if (grid[i][j] == '0') {
					if (i == 0) {
						C[i][j] = 0;
					}
					else {
						C[i][j] = C[i - 1][j];
					}
				}
				else {
					if (i == 0) {
						C[i][j] = 1;
					}
					else {
						C[i][j] = 1 + C[i - 1][j];
					}
				}
			}
		}
		for (j = 0; j < Y; ++j) {
			for (i = X - 1; i >= 0; --i) {
				if (grid[i][j] == 'W') {
					D[i][j] = 0;
				}
				else if (grid[i][j] == '0') {
					if (i == X - 1) {
						D[i][j] = 0;
					}
					else {
						D[i][j] = D[i + 1][j];
					}
				}
				else {
					if (i == X - 1) {
						D[i][j] = 1;
					}
					else {
						D[i][j] = 1 + D[i + 1][j];
					}
				}
			}
		}
		for (i = 0; i < X; ++i) {
			for (j = 0; j < Y; ++j) {
				curr = A[i][j] + B[i][j] + C[i][j] + D[i][j];
				if (grid[i][j] == '0' and result < curr) {
					result = curr;
				}
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<vector<char>> grid;
	int result;

	grid = {{'0', 'E', '0', '0'}, {'E', '0', 'W', 'E'}, {'0', 'E', '0', '0'}};
	result = solution.maxKilledEnemies(grid);
	cout << result << '\n';

	return 0;
}