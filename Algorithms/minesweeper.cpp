// 529. Minesweeper
// https://leetcode.com/problems/minesweeper/
#include <iostream>
#include <cassert>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		vector<vector<char>> result(board);
		const int p = board.size();
		const int q = board.front().size();
		if (click[0] < 0 || click[0] >= p || click[1] < 0 || click[1] >= q) {
			return result;
		}
		if (result[click[0]][click[1]] == 'M') {
			result[click[0]][click[1]] = 'X';
			return result;
		}
		if (result[click[0]][click[1]] == 'E') {
			const vector<int> dx = {-1, 0, 1, 0, -1, -1, 1, 1};
			const vector<int> dy = {0, -1, 0, 1, -1, 1, -1, 1};
			list<vector<int>> queue;
			queue.push_back(click);
			while (!queue.empty()) {
				const vector<int> queue_front = queue.front();
				queue.pop_front();
				int cnt = 0;
				for (int i = 0; i < 8; i++) {
					const int x = dx[i] + queue_front[0];
					const int y = dy[i] + queue_front[1];
					if (x >= 0 && x < p && y >= 0 && y < q) {
						if (board[x][y] == 'M') {
							cnt++;
						}
					}
				}
				if (cnt == 0) {
					result[queue_front[0]][queue_front[1]] = 'B';
					for (int i = 0; i < 8; i++) {
						const int x = dx[i] + queue_front[0];
						const int y = dy[i] + queue_front[1];
						if (x >= 0 && x < p && y >= 0 && y < q && result[x][y] == 'E') {
							queue.push_back(vector<int>({x, y}));
						}
					}
				}
				else {
					result[queue_front[0]][queue_front[1]] = '0' + cnt;
				}
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<vector<char>> board;
	vector<int> click;
	vector<vector<char>> result;
	vector<vector<char>> answer;

	board = {{'E', 'E', 'E', 'E', 'E'}, {'E', 'E', 'M', 'E', 'E'}, {'E', 'E', 'E', 'E', 'E'}, {'E', 'E', 'E', 'E', 'E'}};
	click = {3, 0};
	answer = {{'B', '1', 'E', '1', 'B'}, {'B', '1', 'M', '1', 'B'}, {'B', '1', '1', '1', 'B'}, {'B', 'B', 'B', 'B', 'B'}};
	result = solution.updateBoard(board, click);
	assert(answer == result);

	board = {{'B', '1', 'E', '1', 'B'}, {'B', '1', 'M', '1', 'B'}, {'B', '1', '1', '1', 'B'}, {'B', 'B', 'B', 'B', 'B'}};
	click = {1, 2};
	answer = {{'B', '1', 'E', '1', 'B'}, {'B', '1', 'X', '1', 'B'}, {'B', '1', '1', '1', 'B'}, {'B', 'B', 'B', 'B', 'B'}};
	result = solution.updateBoard(board, click);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}