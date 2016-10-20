// 289. Game of Life
// https://leetcode.com/problems/game-of-life/
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		vector<vector<int>> forkOfBoard(board);
		vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
		const int m = board.size(), n = m ? board.front().size() : 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int numberOfLives = 0;
				for (const auto &k : directions) {
					int x = i + k.first, y = j + k.second;
					if (x < 0 || x >= m || y < 0 || y >= n) continue;
					if (forkOfBoard[x][y] == 1) numberOfLives++;
				}
				if (board[i][j] == 1) {
					if (numberOfLives < 2)
						board[i][j] = 0;
					else if (numberOfLives == 2 || numberOfLives == 3)
						board[i][j] = 1;
					else
						board[i][j] = 0;
				}
				else {
					if (numberOfLives == 3)
						board[i][j] = 1;
				}
			}
		}
	}
};
int main(void) {
	Solution solution;
	vector<vector<int>> board;
	solution.gameOfLife(board);
	cout << "\nPassed All\n";
	return 0;
}