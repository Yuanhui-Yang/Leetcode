// 695. Max Area of Island
// https://leetcode.com/problems/max-area-of-island/

/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
*/

#include <iostream>
#include <vector>
#include <array>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int result = 0, i, j, X = grid.size(), Y = X == 0 ? 0 : grid[0].size();
		for (i = 0; i < X; ++i) {
			for (j = 0; j < Y; ++j) {
				if (grid[i][j] == 1) {
					result = max(result, f1(grid, {i, j}));
				}
			}
		}
		return result;
	}
private:
	int f1(vector<vector<int>>& grid, array<int, 2> p) {
		int result = 0, i, j, X = grid.size(), Y = X == 0 ? 0 : grid[0].size();
		array<int, 4> dx({-1, 0, 1, 0}), dy({0, -1, 0, 1});
		stack<array<int, 2>> s;
		s.push(p);
		grid[p[0]][p[1]] = 0;
		while (!s.empty()) {
			++result;
			p = s.top();
			s.pop();
			for (i = 0; i < 4; ++i) {
				p[0] += dx[i];
				p[1] += dy[i];
				if (p[0] >= 0 and p[0] < X and p[1] >= 0 and p[1] < Y and grid[p[0]][p[1]] == 1) {
					grid[p[0]][p[1]] = 0;
					s.push(p);
				}
				p[0] -= dx[i];
				p[1] -= dy[i];
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<vector<int>> grid;
	int result;
	
	grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
	result = solution.maxAreaOfIsland(grid);
	cout << result << '\n';

	grid = {{0, 0, 0, 0, 0, 0, 0, 0}};
	result = solution.maxAreaOfIsland(grid);
	cout << result << '\n';
	
	return 0;
}