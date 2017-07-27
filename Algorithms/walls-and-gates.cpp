// 286. Walls and Gates
// https://leetcode.com/problems/walls-and-gates/

/*
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/

class Solution {
public:
	void wallsAndGates(vector<vector<int>>& rooms) {
		int M = rooms.size(), N = M == 0 ? 0 : rooms[0].size();
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				f(rooms, i, j, M, N);
			}
		}
	}
private:
	void f(vector<vector<int>> & rooms, int x, int y, int M, int N) {
		if (x < 0 or x >= M or y < 0 or y >= N or rooms[x][y] != 0) {
			return;
		}
		queue<array<int, 2>> q;
		q.push({x, y});
		array<int, 4> dx = {0, -1, 0, 1}, dy = {-1, 0, 1, 0};
		while (!q.empty()) {
			array<int, 2> np = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = np[0] + dx[i], ny = np[1] + dy[i];
				if (nx >= 0 and nx < M and ny >= 0 and ny < N and rooms[np[0]][np[1]] + 1 < rooms[nx][ny]) {
					rooms[nx][ny] = rooms[np[0]][np[1]] + 1;
					q.push({nx, ny});
				}
			}
		}
	}
};