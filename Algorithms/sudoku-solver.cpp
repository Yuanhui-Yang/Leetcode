// 37. Sudoku Solver
// https://leetcode.com/problems/sudoku-solver/

/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...


...and its solution numbers marked in red.
*/

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		array<array<int, 9>, 3> A;
		A[0].fill(0);
		A[1].fill(0);
		A[2].fill(0);
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					int k = i / 3 * 3 + j / 3, val = board[i][j] - '1', mask = 1 << val;
					A[0][i] |= mask;
					A[1][j] |= mask;
					A[2][k] |= mask;
				}
			}
		}
		array<int, 2> curr;
		curr.fill(0);
		f(board, A, curr);
	}
private:
	bool f(vector<vector<char>> & board, array<array<int, 9>, 3> & A, array<int, 2> curr) {
		int x = curr[0], y = curr[1], z = x / 3 * 3 + y / 3;
		if (x >= 9) {
			return true;
		}
		if (y >= 9) {
			++curr[0];
			curr[1] = 0;
			return f(board, A, curr);
		}
		if (board[x][y] != '.') {
			++curr[1];
			return f(board, A, curr);
		}
		for (int i = 0; i < 9; ++i) {
			int mask = 1 << i;
			if (!(A[0][x] & mask) and !(A[1][y] & mask) and !(A[2][z] & mask)) {
				A[0][x] |= mask;
				A[1][y] |= mask;
				A[2][z] |= mask;
				board[x][y] = '1' + i;
				++curr[1];
				if (f(board, A, curr)) {
					return true;
				}
				A[0][x] &= ~mask;
				A[1][y] &= ~mask;
				A[2][z] &= ~mask;
				board[x][y] = '.';
				--curr[1];
			}
		}
		return false;
	}
};