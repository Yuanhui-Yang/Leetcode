// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
// BEGIN: http://www.jiuzhang.com/solutions/number-of-islands/
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		const int grid_nrows = grid.size();
		const int grid_ncols = grid_nrows ? grid[0].size() : 0;
		if (!grid_nrows || !grid_ncols) return 0;
		int result = grid_nrows * grid_ncols;
		vector<int> father(grid_nrows * grid_ncols, 0);
		for (int i = 0; i < grid_nrows * grid_ncols; i++) {
			father[i] = i;
		}
		const vector<int> dx = { -1, 0, 1, 0 };
		const vector<int> dy = { 0, -1, 0, 1 };
		for (int i = 0; i < grid_nrows; i++) {
			for (int j = 0; j < grid_ncols; j++) {
				if (grid[i][j] == '1') {
					for (int k = 0; k < 4; k++) {
						int x = i + dx[k];
						int y = j + dy[k];
						if (x >= 0 && x < grid_nrows && y >= 0 && y < grid_ncols && grid[x][y] == '1') {
							int key_ij = j + grid_ncols * i;
							int root_ij = find(key_ij, father);
							int key_xy = y + grid_ncols * x;
							int root_xy = find(key_xy, father);
							if (root_xy != root_ij) {
								father[root_ij] = root_xy;
								result--;
							}
						}
					}
				}
				else result--;
			}
		}
		return result;
	}
private:
	int find(int x, vector<int>& father) {
		if (x == father[x]) return x;
		return father[x] = find(father[x], father);
	}
};
// END: http://www.jiuzhang.com/solutions/number-of-islands/
// BEGIN: https://discuss.leetcode.com/topic/13248/very-concise-java-ac-solution
// class Solution {
// public:
// 	int numIslands(vector<vector<char>>& grid) {
// 		int result = 0;
// 		for (int i = 0; i < grid.size(); ++i) {
// 			for (int j = 0; j < grid.front().size(); ++j) {
// 				if (grid[i][j] == '1') {
// 					this->DFS(i - 1, j, grid);
// 					this->DFS(i + 1, j, grid);
// 					this->DFS(i, j - 1, grid);
// 					this->DFS(i, j + 1, grid);
// 					++result;
// 				}
// 			}
// 		}
// 		return result;
// 	}
// private:
// 	void DFS(int i, int j, vector<vector<char>>& grid) {
// 		if (i < 0 || i >= grid.size() || j < 0 || j >= grid.front().size()) return;
// 		if (grid[i][j] == '0') return;
// 		grid[i][j] = '0';
// 		this->DFS(i - 1, j, grid);
// 		this->DFS(i + 1, j, grid);
// 		this->DFS(i, j - 1, grid);
// 		this->DFS(i, j + 1, grid);
// 		return;
// 	}
// };
// END: https://discuss.leetcode.com/topic/13248/very-concise-java-ac-solution
int main(void) {
	Solution solution;
	vector<vector<char>> grid;
	int result = 0;
	grid = { { '1', '1', '1', '1', '0' },{ '1', '1', '0', '1', '0' },{ '1', '1', '0', '0', '0' },{ '0', '0', '0', '0', '0' } };
	result = solution.numIslands(grid);
	assert(1 == result);
	grid = { { '1', '1', '0', '0', '0' },{ '1', '1', '0', '0', '0' },{ '0', '0', '1', '0', '0' },{ '0', '0', '0', '1', '1' } };
	result = solution.numIslands(grid);
	assert(3 == result);
	cout << "\nPassed All\n";
	return 0;
}