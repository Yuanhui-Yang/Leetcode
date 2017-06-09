// 463. Island Perimeter
// https://leetcode.com/problems/island-perimeter/

/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		if (grid.empty() or grid.front().empty()) {
			return 0;
		}
		int m = grid.size(), n = grid.front().size(), x = 0, y = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 0) {
					continue;
				}
				++x;
				if (i > 0 and grid[i - 1][j] == 1) {
					++y;
				}
				if (j > 0 and grid[i][j - 1] == 1) {
					++y;
				}
			}
		}
		return 4 * x - 2 * y;
	}
};

// class Solution {
// public:
// 	int islandPerimeter(vector<vector<int>>& grid) {
// 		if (grid.empty() or grid.front().empty()) {
// 			return 0;
// 		}
// 		int m = grid.size(), n = grid.front().size();
// 		queue<pair<int, int>> q;
// 		bool flag = true;
// 		for (int i = 0; flag and i < m; ++i) {
// 			for (int j = 0; flag and j < n; ++j) {
// 				if (grid[i][j] == 1) {
// 					grid[i][j] = -1;
// 					q.push(make_pair(i, j));
// 					flag = false;
// 				}
// 			}
// 		}
// 		int result = 0, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
// 		while (!q.empty()) {
// 			pair<int, int> f = q.front();
// 			q.pop();
// 			int x = f.first, y = f.second;
// 			for (int i = 0; i < 4; ++i) {
// 				int nx = x + dx[i], ny = y + dy[i];
// 				if (nx < 0 or nx >= m or ny < 0 or ny >= n or grid[nx][ny] == 0) {
// 					++result;
// 					continue;
// 				}
// 				if (grid[nx][ny] < 0) {
// 					continue;
// 				}
// 				grid[nx][ny] = -1;
// 				q.push(make_pair(nx, ny));
// 			}
// 		}
// 		return result;
// 	}
// };

int main(void) {
	Solution solution;
	vector<vector<int>> grid;
	int answer, result;

	grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
	answer = 16;
	result = solution.islandPerimeter(grid);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}