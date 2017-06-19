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
				if (board[i][j] == '.') {
					continue;
				}
				int val = 1 << (board[i][j] - '1'), k = i / 3 * 3 + j / 3;
				a[i] |= val;
				b[j] |= val;
				c[k] |= val;
			}
		}
		dfs(board, a, b, c, 0, 0);
	}
private:
	bool dfs(vector<vector<char>>& board, int* a, int* b, int* c, int i, int j) {
		if (i == 9) {
			return true;
		}
		while (j < 9 and board[i][j] != '.') {
			++j;
		}
		if (j == 9) {
			return dfs(board, a, b, c, i + 1, 0);
		}
		int k = i / 3 * 3 + j / 3;
		for (int l = 0; l < 9; ++l) {
			int val = 1 << l;
			if (!(a[i] & val) and !(b[j] & val) and !(c[k] & val)) {
				board[i][j] = '1' + l;
				a[i] |= val;
				b[j] |= val;
				c[k] |= val;
				if (dfs(board, a, b, c, i, j + 1)) {
					return true;
				}
				a[i] &= ~val;
				b[j] &= ~val;
				c[k] &= ~val;
				board[i][j] = '.';
			}
		}
		return false;
	}
};

int main(void) {
	Solution solution;
	vector<string> result, answer;
	vector<vector<char>> board;

	result = {"..9748...", "7........", ".2.1.9...", "..7...24.", ".64.1.59.", ".98...3..", "...8.3.2.", "........6", "...2759.."};
	board.clear();
	for (const auto &i : result) {
		board.push_back(vector<char>(begin(i), end(i)));
	}
	answer = {"519748632", "783652419", "426139875", "357986241", "264317598", "198524367", "975863124", "832491756", "641275983"};
	solution.solveSudoku(board);
	result.clear();
	for (const auto &i : board) {
		result.push_back(string(begin(i), end(i)));
	}
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}