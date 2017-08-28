// 36. Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/

/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		array<int, 9> X, Y, Z;
		X.fill(0);
		Y.fill(0);
		Z.fill(0);
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (isdigit(board[i][j])) {
					int k = i / 3 * 3 + j / 3, mask = 1 << (board[i][j] - '0');
					if ((X[i] & mask) or (Y[j] & mask) or (Z[k] & mask)) {
						return false;
					}
					else {
						X[i] |= mask;
						Y[j] |= mask;
						Z[k] |= mask;
					}
				}
			}
		}
		return true;
	}
};