// 694. Number of Distinct Islands
// https://leetcode.com/problems/number-of-distinct-islands/

/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Example 1:
11000
11000
00011
00011
Given the above grid map, return 1.
Example 2:
11011
10000
00001
11011
Given the above grid map, return 3.

Notice that:
11
1
and
 1
11
are considered different island shapes, because we do not consider reflection / rotation.
Note: The length of each dimension in the given grid does not exceed 50.
*/

#include <iostream>
#include <stack>
#include <set>
#include <array>
#include <vector>

using namespace std;

class Solution {
public:
	int numDistinctIslands(vector<vector<int>>& grid) {
		set<vector<array<int, 2>>> A;
		int X = grid.size(), Y = X == 0 ? 0 : grid[0].size(), i, j;
		for (i = 0; i < X; ++i) {
			for (j = 0; j < Y; ++j) {
				if (grid[i][j] == 1) {
					A.insert(f1(grid, {i, j}));
				}
			}
		}
		return A.size();
	}
private:
	vector<array<int, 2>> f1(vector<vector<int>> & grid, array<int, 2> p) {
		int X = grid.size(), Y = X == 0 ? 0 : grid[0].size(), i;
		vector<array<int, 2>> result;
		array<int, 4> dx({-1, 0, 1, 0}), dy({0, -1, 0, 1});
		array<int, 2> r;
		stack<array<int, 2>> s;
		s.push(p);
		grid[p[0]][p[1]] = 0;
		while (!s.empty()) {
			r = s.top();
			s.pop();
			result.push_back({r[0] - p[0], r[1] - p[1]});
			for (i = 0; i < 4; ++i) {
				r[0] += dx[i];
				r[1] += dy[i];
				if (r[0] >= 0 and r[0] < X and r[1] >= 0 and r[1] < Y and grid[r[0]][r[1]] == 1) {
					grid[r[0]][r[1]] = 0;
					s.push(r);
				}
				r[0] -= dx[i];
				r[1] -= dy[i];
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<vector<int>> grid;
	int result;
	
	grid = {{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}};
	result = solution.numDistinctIslands(grid);
	cout << result << '\n';
	
	grid = {{1, 1, 0, 1, 1}, {1, 0, 0, 0, 0}, {0, 0, 0, 0, 1}, {1, 1, 0, 1, 1}};
	result = solution.numDistinctIslands(grid);
	cout << result << '\n';

	return 0;
}

#include <iostream>
#include <queue>
#include <set>
#include <array>
#include <vector>

using namespace std;

class Solution {
public:
	int numDistinctIslands(vector<vector<int>>& grid) {
		set<vector<array<int, 2>>> A;
		int X = grid.size(), Y = X == 0 ? 0 : grid[0].size(), i, j;
		for (i = 0; i < X; ++i) {
			for (j = 0; j < Y; ++j) {
				if (grid[i][j] == 1) {
					A.insert(f1(grid, {i, j}));
				}
			}
		}
		return A.size();
	}
private:
	vector<array<int, 2>> f1(vector<vector<int>> & grid, array<int, 2> p) {
		int X = grid.size(), Y = X == 0 ? 0 : grid[0].size(), i;
		vector<array<int, 2>> result;
		array<int, 4> dx({-1, 0, 1, 0}), dy({0, -1, 0, 1});
		array<int, 2> r;
		queue<array<int, 2>> q;
		q.push(p);
		grid[p[0]][p[1]] = 0;
		while (!q.empty()) {
			r = q.front();
			q.pop();
			result.push_back({r[0] - p[0], r[1] - p[1]});
			for (i = 0; i < 4; ++i) {
				r[0] += dx[i];
				r[1] += dy[i];
				if (r[0] >= 0 and r[0] < X and r[1] >= 0 and r[1] < Y and grid[r[0]][r[1]] == 1) {
					grid[r[0]][r[1]] = 0;
					q.push(r);
				}
				r[0] -= dx[i];
				r[1] -= dy[i];
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<vector<int>> grid;
	int result;
	
	grid = {{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}};
	result = solution.numDistinctIslands(grid);
	cout << result << '\n';
	
	grid = {{1, 1, 0, 1, 1}, {1, 0, 0, 0, 0}, {0, 0, 0, 0, 1}, {1, 1, 0, 1, 1}};
	result = solution.numDistinctIslands(grid);
	cout << result << '\n';

	return 0;
}