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
        for (int x = 0; x < X; ++x) {
            vector<int> curr_row(board[x]);
            for (int y = 0; y < Y; ++y) {
                int nlive = f1(board, prev_row, curr_row, x, y);
                f2(board, nlive, x, y);
            }
            prev_row = curr_row;
        }
    }
private:
    int f1(vector<vector<int>> & board, vector<int> & prev_row, vector<int> & curr_row, int x, int y) {
        int nlive = 0, X = board.size(), Y = X ? board[0].size() : 0;
        array<int, 8> dx{-1, -1, -1, 0, 0, 1, 1, 1}, dy{-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 and nx < X and ny >= 0 and ny < Y) {
                if (nx == x) {
                    nlive += curr_row[ny] == 1;
                }
                else if (nx < x) {
                    nlive += prev_row[ny] == 1;
                }
                else {
                    nlive += board[nx][ny] == 1;
                }
            }
        }
        return nlive;
    }
    void f2(vector<vector<int>> & board, int nlive, int x, int y) {
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
};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int X = board.size(), Y = X ? board[0].size() : 0;
        for (int x = 0; x < X; ++x) {
            for (int y = 0; y < Y; ++y) {
                int nlive = f1(board, x, y);
                f2(board, x, y, nlive);
            }
        }
        f3(board);
    }
private:
    int f1(vector<vector<int>>& board, int x, int y) {
        int result = 0, X = board.size(), Y = X ? board[0].size() : 0;
        array<int, 8> dx{-1, -1, -1, 0, 0, 1, 1, 1}, dy{-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 and nx < X and ny >= 0 and ny < Y) {
                result += board[nx][ny] & 1;
            }
        }
        return result;
    }
    void f2(vector<vector<int>>& board, int x, int y, int nlive) {
        if (board[x][y]) {
            if (nlive == 2 or nlive == 3) {
                board[x][y] ^= 0b10;
            }
        }
        else {
            if (nlive == 3) {
                board[x][y] ^= 0b10;
            }
        }
    }
    void f3(vector<vector<int>>& board) {
        for (auto & i : board) {
            for (auto & j : i) {
                j >>= 1;
            }
        }
    }
};
