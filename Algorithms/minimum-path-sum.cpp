// 64. Minimum Path Sum
// https://leetcode.com/problems/minimum-path-sum/

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty() or grid.front().empty()) {
			return 0;
		}
		int m = grid.size(), n = grid.front().size();
		vector<int> M(n, INT_MAX);
		M.back() = 0;
		for (int i = m - 1; i >= 0; --i) {
			M.back() += grid[i].back();
			for (int j = n - 2; j >= 0; --j) {
				M[j] = min(M[j], M[j + 1]) + grid[i][j];
			}
		}
		return M.front();
	}
};

int main(void) {
	Solution solution;
	vector<vector<int>> grid;
	int answer, result;

	grid = {{0}};
	answer = 0;
	result = solution.minPathSum(grid);
	assert(answer == result);

	grid = {{1, 2}, {1, 1}};
	answer = 3;
	result = solution.minPathSum(grid);
	assert(answer == result);

	grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
	answer = 7;
	result = solution.minPathSum(grid);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}