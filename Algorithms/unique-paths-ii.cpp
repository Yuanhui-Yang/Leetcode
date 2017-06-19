// 63. Unique Paths II
// https://leetcode.com/problems/unique-paths-ii/

/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty() or obstacleGrid.front().empty() or obstacleGrid.front().front() == 1 or obstacleGrid.back().back() == 1) {
			return 0;
		}
		int m = obstacleGrid.size(), n = obstacleGrid.front().size();
		vector<int> OPT(n, 0);
		OPT.back() = 1;
		for (int i = m - 1; i >= 0; --i) {
			OPT.back() = min(OPT.back(), 1 - obstacleGrid[i].back());
			for (int j = n - 2; j >= 0; --j) {
				OPT[j] = obstacleGrid[i][j] == 1 ? 0 : OPT[j] + OPT[j + 1];
			}
		}
		return OPT[0];
	}
};

int main(void) {
	Solution solution;
	vector<vector<int>> obstacleGrid;
	int answer, result;

	obstacleGrid = {{0, 0}, {1, 0}};
	answer = 1;
	result = solution.uniquePathsWithObstacles(obstacleGrid);
	assert(answer == result);

	obstacleGrid = {{1, 0}};
	answer = 0;
	result = solution.uniquePathsWithObstacles(obstacleGrid);
	assert(answer == result);

	obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
	answer = 2;
	result = solution.uniquePathsWithObstacles(obstacleGrid);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}