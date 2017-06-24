// 79. Word Search
// https://leetcode.com/problems/word-search/

/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size(), n = !m ? 0 : board.front().size(), l = word.size();
		if (!m or !n or !l) {
			return false;
		}
		int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dfs(board, word, dx, dy, i, j, 0)) {
					return true;
				}
			}
		}
		return false;
	}
private:
	bool dfs(vector<vector<char>>& board, string& word, int *dx, int *dy, int i, int j, int k) {
		int m = board.size(), n = !m ? 0 : board.front().size(), l = word.size();
		if (k >= l) {
			return true;
		}
		if (i < 0 or i >= m or j < 0 or j >= n or board[i][j] != word[k]) {
			return false;
		}
		char ch = board[i][j];
		board[i][j] = ' ';
		for (int l = 0; l < 4; ++l) {
			int nx = i + dx[l], ny = j + dy[l];
			if (dfs(board, word, dx, dy, nx, ny, k + 1)) {
				return true;
			}
		}
		board[i][j] = ch;
		return false;
	}
};

int main(void) {
	Solution solution;
	vector<vector<char>> board;
	string word;
	bool answer, result;

	board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	word = "ABCCED";
	answer = true;
	result = solution.exist(board, word);
	assert(answer == result);

	board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	word = "SEE";
	answer = true;
	result = solution.exist(board, word);
	assert(answer == result);

	board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	word = "ABCB";
	answer = false;
	result = solution.exist(board, word);
	assert(answer == result);

	board = {{'a', 'b'}};
	word = "ba";
	answer = true;
	result = solution.exist(board, word);
	assert(answer == result);

	board = {{'a'}};
	word = "a";
	answer = true;
	result = solution.exist(board, word);
	assert(answer == result);

	board = {{'a', 'a'}};
	word = "aaa";
	answer = false;
	result = solution.exist(board, word);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}