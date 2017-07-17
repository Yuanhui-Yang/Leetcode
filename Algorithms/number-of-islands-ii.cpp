// 305. Number of Islands II
// https://leetcode.com/problems/number-of-islands-ii/

/*
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]

Challenge:

Can you do it in time complexity O(k log mn), where k is the length of the positions?
*/

class Solution {
public:
	vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
		int sz = m * n, cnt = 0;
		vector<int> A(sz, -1);
		vector<int> result;
		for (const auto & i : positions) {
			cnt = f(A, m, n, i.first, i.second, cnt);
			result.push_back(cnt);
		}
		return result;
	}
private:
	int f(vector<int> & A, int m, int n, int x, int y, int cnt) {
		int id = y + x * n;
		if (A[id] >= 0) {
			return 0;
		}
		A[id] = id;
		int result = 1 + cnt, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 and nx < m and ny >= 0 and ny < n) {
				int nid = ny + n * nx;
				if (A[nid] >= 0) {
					int r = g(A, id), nr = g(A, nid);
					if (r != nr) {
						--result;
						A[r] = nr;
					}
				}
			}
		}
		return result;
	}
	int g(vector<int> & A, int id) {
		return A[id] == id ? id : A[id] = g(A, A[id]);
	}
	// int g(vector<int> & A, int id) {
	//     while (A[id] != id) {
	//         A[id] = A[A[id]];
	//         id = A[id];
	//     }
	//     return id;
	// }
};