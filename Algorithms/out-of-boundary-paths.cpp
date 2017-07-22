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

class Solution {
public:
	int findPaths(int m, int n, int N, int i, int j) {
		if (m <= 0 or n <= 0 or N <= 0 or i < 0 or i >= m or j < 0 or j >= n) {
			return 0;
		}
		vector<vector<vector<long long>>> A(N + 1, vector<vector<long long>>(m, vector<long long>(n, -1LL)));
		return f(A, m, n, N, i, j);
	}
private:
	long long f(vector<vector<vector<long long>>> & A, int m, int n, int N, int x, int y) {
		if (N < 0) {
			return 0;
		}
		if (x < 0 or x >= m or y < 0 or y >= n) {
			return 1;
		}
		if (N == 0) {
			return 0;
		}
		if (A[N][x][y] >= 0) {
			return A[N][x][y];
		}
		long long result = 0, C = 1e9 + 7;
		result += f(A, m, n, N - 1, x - 1, y) % C;
		result += f(A, m, n, N - 1, x + 1, y) % C;
		result += f(A, m, n, N - 1, x, y - 1) % C;
		result += f(A, m, n, N - 1, x, y + 1) % C;
		result %= C;
		return A[N][x][y] = result;
	}
};