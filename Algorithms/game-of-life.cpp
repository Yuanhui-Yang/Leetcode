// 289. Game of Life
// https://leetcode.com/problems/game-of-life/

/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int X = board.size(), Y = X ? board[0].size() : 0;
        vector<int> prev_row(Y, -1);
        array<int, 8> dx{-1, -1, -1, 0, 0, 1, 1, 1}, dy{-1, 0, 1, -1, 1, -1, 0, 1};
        for (int x = 0; x < X; ++x) {
            vector<int> curr_row(board[x]);
            for (int y = 0; y < Y; ++y) {
                int curr_col = board[x][y], nlive = 0, ndead = 0;
                for (int i = 0; i < 8; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx >= 0 and nx < X and ny >= 0 and ny < Y) {
                        if (nx == x) {
                            nlive += curr_row[ny] == 1;
                            ndead += curr_row[ny] == 0;
                        }
                        else if (nx < x) {
                            nlive += prev_row[ny] == 1;
                            ndead += prev_row[ny] == 0;
                        }
                        else {
                            nlive += board[nx][ny] == 1;
                            ndead += board[nx][ny] == 0;
                        }
                    }
                }
                if (board[x][y]) {
                    if (nlive < 2) {
                        board[x][y] = 0;
                    }
                    else if (nlive > 3) {
                        board[x][y] = 0;
                    }
                }
                else {
                    if (nlive == 3) {
                        board[x][y] = 1;
                    }
                }
            }
            prev_row = curr_row;
        }
    }
};

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int M = board.size(), N = M == 0 ? 0 : board[0].size();
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				board[i][j] = f(board, i, j, M, N);
			}
		}
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				board[i][j] = g(board, i, j);
			}
		}
	}
private:
	int f(vector<vector<int>>& board, int x, int y, int M, int N) {
		array<int, 8> dx = {-1, 0, 1, 0, -1, -1, 1, 1}, dy = {0, -1, 0, 1, -1, 1, -1, 1};
		int cnt = 0;
		for (int i = 0; i < 8; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 and nx < M and ny >= 0 and ny < N and (1 & board[nx][ny])) {
				++cnt;
			}
		}
		int z = board[x][y], mask = 1 << 16;
		if (1 & z) {
			if (cnt == 2 or cnt == 3) {
				return z | mask;
			}
			return z;
		}
		if (cnt == 3) {
			return z | mask;
		}
		return z;
	}
	int g(vector<vector<int>>& board, int x, int y) {
		int z = board[x][y], mask = 1 << 16;
		return (z & mask) >> 16;
	}
};
