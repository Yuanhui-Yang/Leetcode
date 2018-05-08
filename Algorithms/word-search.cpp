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
        for (int X = board.size(), i = 0; i < X; ++i) {
            for (int Y = X ? board[0].size() : 0, j = 0; j < Y; ++j) {
                if (f1(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool f1(vector<vector<char>>& board, string & word, int start, int x, int y) {
        int sz = word.size(), X = board.size(), Y = X ? board[0].size() : 0;
        if (start == sz) {
            return true;
        }
        if (x < 0 or x >= X or y < 0 or y >= Y or board[x][y] != word[start]) {
            return false;
        }
        board[x][y] = -1;
        array<int, 4> dx = {0, -1, 0, 1}, dy = {-1, 0, 1, 0};
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (f1(board, word, start + 1, nx, ny)) {
                return true;
            }
        }
        board[x][y] = word[start];
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
