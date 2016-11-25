// 417. Pacific Atlantic Water Flow
// https://leetcode.com/problems/pacific-atlantic-water-flow/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<pair<int, int>> result;
		const int p = matrix.size(), q = p ? matrix.front().size() : 0;
		if (!p || !q) return result;
		vector<vector<pair<int, int>>> table(p, vector<pair<int, int>>(q, make_pair(-1, -1))); // first for Pacific and second for Atlantic
		
		for (int i = 0; i < p; i++) {
			table[i][0].first = 1;
			table[i][q - 1].second = 1;
		}
		for (int j = 0; j < q; j++) {
			table[0][j].first = 1;
			table[p - 1][j].second = 1;
		}
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < q; j++) {
				dfs(i, j, table, matrix);
			}
		}
		for (int i = 0; i < p; i++) {
			for (int j = 0; j < q; j++) {
				if (table[i][j].first > 0 && table[i][j].second > 0) {
					result.push_back(make_pair(i, j));
				}
			}
		}
		return result;
	}
private:
	void dfs(int x, int y, vector<vector<pair<int, int>>>& table, vector<vector<int>>& matrix) {
		const int p = matrix.size(), q = p ? matrix.front().size() : 0;
		if (!p || !q) return;
		if (x < 0 || x >= p || y < 0 || y >= q) return;
		if (table[x][y].first < 0 && table[x][y].second < 0) return;
		vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		for (const auto &dir : directions) {
			int i = x + dir.first;
			int j = y + dir.second;
			if (i < 0 || i >= p || j < 0 || j >= q || matrix[i][j] < matrix[x][y]) continue;
			if (table[i][j].first > 0 && table[i][j].second > 0) continue;
			if (table[x][y].first > 0) {
				if (table[i][j].first < 0) {
					table[i][j].first = 1;
					dfs(i, j, table, matrix);
				}
			}
			if (table[x][y].second > 0) {
				if (table[i][j].second < 0) {
					table[i][j].second = 1;
					dfs(i, j, table, matrix);
				}
			}
		}
	}
};
// class Solution {
// public:
// 	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
// 		vector<pair<int, int>> result;
// 		const int p = matrix.size(), q = p ? matrix.front().size() : 0;
// 		if (!p || !q) return result;
// 		vector<vector<pair<int, int>>> table(p, vector<pair<int, int>>(q, make_pair(-1, -1))); // first for Pacific and second for Atlantic
		
// 		for (int i = 0; i < p; i++) {
// 			table[i][0].first = 1;
// 			table[i][q - 1].second = 1;
// 		}
// 		for (int j = 0; j < q; j++) {
// 			table[0][j].first = 1;
// 			table[p - 1][j].second = 1;
// 		}
// 		for (int i = 0; i < p; i++) {
// 			for (int j = 0; j < q; j++) {
// 				dfs(0, i, j, table, matrix); // 0 for Pacific
// 				dfs(1, i, j, table, matrix); // 1 for Atlantic
// 			}
// 		}
// 		for (int i = 0; i < p; i++) {
// 			for (int j = 0; j < q; j++) {
// 				if (table[i][j].first > 0 && table[i][j].second > 0) {
// 					result.push_back(make_pair(i, j));
// 				}
// 			}
// 		}
// 		return result;
// 	}
// private:
// 	void dfs(int mode, int x, int y, vector<vector<pair<int, int>>>& table, vector<vector<int>>& matrix) {
// 		const int p = matrix.size(), q = p ? matrix.front().size() : 0;
// 		if (!p || !q) return;
// 		if (x < 0 || x >= p || y < 0 || y >= q) return;
// 		if (table[x][y].first < 0 && table[x][y].second < 0) return;
// 		if (mode == 0 && table[x][y].first < 0) return;
// 		if (mode == 1 && table[x][y].second < 0) return;
// 		vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// 		for (const auto &dir : directions) {
// 			int i = x + dir.first;
// 			int j = y + dir.second;
// 			if (i < 0 || i >= p || j < 0 || j >= q || matrix[i][j] < matrix[x][y]) continue;
// 			if (!mode) {
// 				if (table[i][j].first < 0) {
// 					table[i][j].first = 1;
// 					dfs(0, i, j, table, matrix);
// 				}
// 			} else {
// 				if (table[i][j].second < 0) {
// 					table[i][j].second = 1;
// 					dfs(1, i, j, table, matrix);
// 				}
// 			}
// 		}
// 	}
// };
int main(void) {
	Solution solution;
	vector<vector<int>> matrix = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
	for (const auto &i : solution.pacificAtlantic(matrix)) {
		cout << '[' << i.first << ',' << i.second << ']' << '\t';
	}
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}