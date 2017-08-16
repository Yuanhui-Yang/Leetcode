// 317. Shortest Distance from All Buildings
// https://leetcode.com/problems/shortest-distance-from-all-buildings/

/*
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
*/

class Solution {
public:
	int shortestDistance(vector<vector<int>>& grid) {
		int P = grid.size(), Q = P == 0 ? 0 : grid[0].size();
		if (P == 0 or Q == 0) {
			return -1;
		}
		array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1}; 
		array<vector<vector<int>>, 2> A;
		A[0].resize(P, vector<int>(Q, 0));
		A[1].resize(P, vector<int>(Q, 0));
		int cnt = 0;
		for (int i = 0; i < P; ++i) {
			for (int j = 0; j < Q; ++j) {
				if (grid[i][j] == 1) {
					++cnt;
					vector<vector<bool>> B(P, vector<bool>(Q, true));
					list<array<int, 2>> curr;
					curr.push_back({i, j});
					B[i][j] = false;
					int depth = 0;
					while (!curr.empty()) {
						++depth;
						list<array<int, 2>> next;
						for (const auto & k : curr) {
							int x = k[0], y = k[1];
							for (int l = 0; l < 4; ++l) {
								int nx = x + dx[l], ny = y + dy[l];
								if (nx >= 0 and nx < P and ny >= 0 and ny < Q and grid[nx][ny] == 0 and B[nx][ny]) {
									B[nx][ny] = false;
									++A[0][nx][ny];
									A[1][nx][ny] += depth;
									next.push_back({nx, ny});
								}
							}
						}
						curr = next;
					}
				}
			}
		}
		int result = -1;
		for (int i = 0; i < P; ++i) {
			for (int j = 0; j < Q; ++j) {
				if (cnt > 0 and A[0][i][j] == cnt) {
					if (result < 0 or A[1][i][j] < result) {
						result = A[1][i][j];
					}
				}
			}
		}
		return result;
	}
};