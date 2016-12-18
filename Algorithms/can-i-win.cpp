// 464. Can I Win
// https://leetcode.com/problems/can-i-win/
#include <iostream>
#include <cassert>
#include <vector>
#include <bitset>
using namespace std;
// BEGIN: Time Limit Exceeded
class Solution {
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if (maxChoosableInteger >= desiredTotal) return true;
		vector<vector<bool>> OPT(1 << maxChoosableInteger, vector<bool>(1 + desiredTotal, false));
		vector<vector<bool>> PATH(1 << maxChoosableInteger, vector<bool>(1 + desiredTotal, false));
		return canIWin(0, 0, maxChoosableInteger, desiredTotal, OPT, PATH);
	}
private:
	bool canIWin(int visited, int sum, const int maxChoosableInteger, const int desiredTotal, vector<vector<bool>>& OPT, vector<vector<bool>>& PATH) {
		if (sum >= desiredTotal) return false;
		if (OPT[visited][sum]) return true;
		if (PATH[visited][sum]) return OPT[visited][sum];
		for (int i = 0; i < maxChoosableInteger; i++) {
			int j = 1 << i;
			if (!(j & visited)) {
				j |= visited;
				if (sum + i + 1 >= desiredTotal) {
					OPT[visited][sum] = true;
					PATH[visited][sum] = true;
					return true;
				}
				if (!canIWin(j, sum + i + 1, maxChoosableInteger, desiredTotal, OPT, PATH)) {
					OPT[visited][sum] = true;
					PATH[visited][sum] = true;
					return true;
				}
			}
		}
		PATH[visited][sum] = true;
		return false;
	}
};
// END: Time Limit Exceeded

// BEGIN: Memory Limit Exceeded
// class Solution {
// public:
// 	bool canIWin(int maxChoosableInteger, int desiredTotal) {
// 		if (maxChoosableInteger >= desiredTotal) return true;
// 		vector<vector<vector<bool>>> F(2, vector<vector<bool>>(1 << maxChoosableInteger, vector<bool>(1 + desiredTotal, false)));
// 		vector<vector<vector<bool>>> G(2, vector<vector<bool>>(1 << maxChoosableInteger, vector<bool>(1 + desiredTotal, false)));
// 		for (int i = 0; i < maxChoosableInteger; i++) {
// 			int j = 1 << i;
// 			if (g(1, j, i + 1, maxChoosableInteger, desiredTotal, F, G)) {
// 				return true;
// 			}
// 		}
// 		return false;
// 	}
// private:
// 	// player has chance to win
// 	bool f(int player, int visited, int sum, int maxChoosableInteger, int desiredTotal, vector<vector<vector<bool>>>& F, vector<vector<vector<bool>>>& G) {
// 		if (sum >= desiredTotal) return false;
// 		if (F[player % 2][visited][sum]) return true;
// 		for (int i = 0; i < maxChoosableInteger; i++) {
// 			int j = 1 << i;
// 			if ((j & visited) == 0) {
// 				j |= visited;
// 				if (sum + i + 1 < 1 + desiredTotal && G[(player + 1) % 2][j][sum + i + 1]) {
// 					F[player % 2][visited][sum] = true;
// 					return true;
// 				}
// 				if (sum + i + 1 >= desiredTotal) {
// 					F[player % 2][visited][sum] = true;
// 					return true;
// 				}
// 			}
// 		}
// 		for (int i = 0; i < maxChoosableInteger; i++) {
// 			int j = 1 << i;
// 			if ((j & visited) == 0) {
// 				j |= visited;
// 				if (g((player + 1) % 2, j, sum + i + 1, maxChoosableInteger, desiredTotal, F, G)) {
// 					F[player % 2][visited][sum] = true;
// 					return true;					
// 				}
// 			}			
// 		}
// 		return false;
// 	}
// 	// player has no chance to win
// 	bool g(int player, int visited, int sum, int maxChoosableInteger, int desiredTotal, vector<vector<vector<bool>>>& F, vector<vector<vector<bool>>>& G) {
// 		if (sum >= desiredTotal) return true;
// 		if (G[player % 2][visited][sum]) return true;
// 		for (int i = 0; i < maxChoosableInteger; i++) {
// 			int j = 1 << i;
// 			if ((j & visited) == 0) {
// 				j |= visited;
// 				if (sum + i + 1 >= desiredTotal) {
// 					return false;
// 				}
// 			}
// 		}
// 		for (int i = 0; i < maxChoosableInteger; i++) {
// 			int j = 1 << i;
// 			if ((j & visited) == 0) {
// 				j |= visited;
// 				if (!f((player + 1) % 2, j, sum + i + 1, maxChoosableInteger, desiredTotal, F, G)) {
// 					return false;
// 				}
// 			}
// 		}
// 		G[player % 2][visited][sum] = true;
// 		return true;
// 	}
// };
// END: Memory Limit Exceeded
int main(void) {
	Solution solution;
	assert(false == solution.canIWin(10, 11));
	assert(true == solution.canIWin(10, 0));
	assert(false == solution.canIWin(10, 40));
	assert(true == solution.canIWin(18, 79));
	assert(true == solution.canIWin(20, 54));
	cout << "\nPassed All\n";
	return 0;
}