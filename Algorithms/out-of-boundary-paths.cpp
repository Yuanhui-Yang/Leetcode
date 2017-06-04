// 576. Out of Boundary Paths
// https://leetcode.com/problems/out-of-boundary-paths/

/*
There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.

Example 1:
Input:m = 2, n = 2, N = 2, i = 0, j = 0
Output: 6
Explanation:

Example 2:
Input:m = 1, n = 3, N = 3, i = 0, j = 1
Output: 12
Explanation:

Note:
Once you move the ball out of boundary, you cannot move it back.
The length and height of the grid is in range [1,50].
N is in range [0,50].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findPaths(int m, int n, int N, int i, int j) {
		vector<vector<vector<size_t>>> OPT(m, vector<vector<size_t>>(n, vector<size_t>(N + 1, string::npos)));
		return dfs(OPT, m, n, N, i, j) % D;
	}
private:
	const size_t D = int(1E9) + 7;
	size_t dfs(vector<vector<vector<size_t>>>& OPT, int m, int n, int N, int i, int j) {
		if (N < 0) {
			return 0;
		}
		if (i < 0 or i >= m or j < 0 or j >= n) {
			return 1;
		}
		if (OPT[i][j][N] != string::npos) {
			return OPT[i][j][N] % D;
		}
		return OPT[i][j][N] = (dfs(OPT, m, n, N - 1, i - 1, j) % D + dfs(OPT, m, n, N - 1, i + 1, j) % D + dfs(OPT, m, n, N - 1, i, j - 1) % D + dfs(OPT, m, n, N - 1, i, j + 1) % D) % D;
	}
};

int main(void) {
	Solution solution;
	int m, n, N, i, j, answer, result;

	m = 8; n = 50; N = 23; i = 5; j = 26;
	answer = 914783380;
	result = solution.findPaths(m, n, N, i, j);
	assert(answer == result);

	m = 1; n = 2; N = 50; i = 0; j = 0;
	answer = 150;
	result = solution.findPaths(m, n, N, i, j);
	assert(answer == result);

	m = 1; n = 3; N = 3; i = 0; j = 1;
	answer = 12;
	result = solution.findPaths(m, n, N, i, j);
	assert(answer == result);

	m = 2; n = 2; N = 2; i = 0; j = 0;
	answer = 6;
	result = solution.findPaths(m, n, N, i, j);
	assert(answer == result);

	m = 1; n = 3; N = 3; i = 0; j = 1;
	answer = 12;
	result = solution.findPaths(m, n, N, i, j);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}