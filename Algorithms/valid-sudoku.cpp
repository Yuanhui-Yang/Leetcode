// 36. Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/

/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
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
				if ((a[i] & mask) or (b[j] & mask) or (c[k] & mask)) {
					return false;
				}
				a[i] |= mask;
				b[j] |= mask;
				c[k] |= mask;
			}
		}
		return true;
	}
};

int main(void) {
	Solution solution;
	vector<vector<char>> board;
	vector<string> matrix;
	bool answer, result;

	matrix = {".87654321", "2........", "3........", "4........", "5........", "6........", "7........", "8........", "9........"};
	answer = true;
	board.clear();
	for (const auto &i : matrix) {
		board.push_back(vector<char>(begin(i), end(i)));
	}
	result = solution.isValidSudoku(board);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}