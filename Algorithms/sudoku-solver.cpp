// 37. Sudoku Solver
// https://leetcode.com/problems/sudoku-solver/

/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...


...and its solution numbers marked in red.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		int a[9], b[9], c[9];
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				char ch = board[i][j];
				if (ch == '.') {
					continue;
				}
				int mask = 1 << (ch - '1'), k = i / 3 * 3 + j / 3;
				a[i] |= mask;
				b[j] |= mask;
				c[k] |= mask;
			}
		}
		dfs(board, a, b, c, 0, 0);
	}
private:
	bool dfs(vector<vector<char>>& board, int* a, int* b, int* c, int i, int j) {
		if (i == 9) {
			return true;
		}
		if (j == 9) {
			return dfs(board, a, b, c, i + 1, 0);
		}
		if (board[i][j] != '.') {
			return dfs(board, a, b, c, i, j + 1);
		}
		for (int k = i / 3 * 3 + j / 3, l = 0; l < 9; ++l) {
			int mask = 1 << l;
			if ((a[i] & mask) or (b[j] & mask) or (c[k] & mask)) {
				continue;
			}
			a[i] |= mask;
			b[j] |= mask;
			c[k] |= mask;
			board[i][j] = '1' + l;
			if (dfs(board, a, b, c, i, j + 1)) {
				return true;
			}
			board[i][j] = '.';
			a[i] &= ~mask;
			b[j] &= ~mask;
			c[k] &= ~mask;
		}
		return false;
	}
};

int main(void) {
	Solution solution;
	vector<string> matrix, answer;
	vector<vector<char>> board;

	matrix = {"..9748...", "7........", ".2.1.9...", "..7...24.", ".64.1.59.", ".98...3..", "...8.3.2.", "........6", "...2759.."};
	answer = {"519748632", "783652419", "426139875", "357986241", "264317598", "198524367", "975863124", "832491756", "641275983"};
	board.clear();
	for (const auto &i : matrix) {
		board.push_back(vector<char>(begin(i), end(i)));
	}
	solution.solveSudoku(board);
	matrix.clear();
	for (const auto &i : board) {
		matrix.push_back(string(begin(i), end(i)));
	}
	assert(answer == matrix);

	cout << "\nPassed All\n";
	return 0;
}