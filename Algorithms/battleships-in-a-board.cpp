// 419. Battleships in a Board
// https://leetcode.com/problems/battleships-in-a-board/
// BEGIN: https://discuss.leetcode.com/topic/62970/simple-java-solution
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {
		int result = 0;
		const int m = board.size(), n = m ? board.front().size() : 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == '.') continue;
				if (i > 0 && board[i - 1][j] == 'X') continue;
				if (j > 0 && board[i][j - 1] == 'X') continue;
				result++;
			}
		}
		return result;
	}
	int countBattleships(vector<string>& board) {
		int result = 0;
		const int m = board.size(), n = m ? board.front().size() : 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == '.') continue;
				if (i > 0 && board[i - 1][j] == 'X') continue;
				if (j > 0 && board[i][j - 1] == 'X') continue;
				result++;
			}
		}
		return result;
	}	
};
// END: https://discuss.leetcode.com/topic/62970/simple-java-solution
int main(void) {
	Solution solution;
	vector<string> board;
	cout << solution.countBattleships(board) << "\tPassed\n";
	board = {"X..X", "...X", "...X"};
	cout << solution.countBattleships(board) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}