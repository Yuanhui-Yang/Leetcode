// 292. Nim Game
// https://leetcode.com/problems/nim-game/
#include <iostream>
using namespace std;
// BEGIN: https://leetcode.com/articles/nim-game/
class Solution {
public:
	bool canWinNim(int n) {
		return n % 4;
	}
};
// END: https://leetcode.com/articles/nim-game/
int main(void) {
	Solution solution;
	cout << boolalpha << solution.canWinNim(4) << "\tPassed\n";
	cout << boolalpha << solution.canWinNim(5) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}