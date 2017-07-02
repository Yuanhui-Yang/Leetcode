// 130. Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/

/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.empty() or board.front().empty()) {
			return;
		}
		int m = board.size(), n = board.front().size(), dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
		for (int i = 0; i < m; ++i) {
			f1(board, m, n, dx, dy, i, 0);
			f1(board, m, n, dx, dy, i, n - 1);
		}
		for (int j = 0; j < n; ++j) {
			f1(board, m, n, dx, dy, 0, j);
			f1(board, m, n, dx, dy, m - 1, j);
		}
		f2(board);
		f3(board);
	}
private:
	void f1(vector<vector<char>>& board, int m, int n, int * dx, int * dy, int x, int y) {
		if (x < 0 or x >= m or y < 0 or y >= n or board[x][y] != 'O') {
			return;
		}
		stack<array<int, 2>> s;
		s.push({x, y});
		while (!s.empty()) {
			array<int, 2> t = s.top();
			s.pop();
			x = t[0];
			y = t[1];
			board[x][y] = 'Y';
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 and nx < m and ny >= 0 and ny < n and board[nx][ny] == 'O') {
					s.push({nx, ny});
				} 
			}
		}
	}
	void f2(vector<vector<char>>& board) {
		for (auto & i : board) {
			for (auto & j : i) {
				if (j == 'O') {
					j = 'X';
				}
			}
		}
	}
	void f3(vector<vector<char>>& board) {
		for (auto & i : board) {
			for (auto & j : i) {
				if (j == 'Y') {
					j = 'O';
				}
			}
		}
	}
};