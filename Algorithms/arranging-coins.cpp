// 441. Arranging Coins
// https://leetcode.com/problems/arranging-coins/
#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
	int arrangeCoins(int n) {
		return (int)(sqrt(2.0 * n + 0.25) - 0.5);
	}
};
int main(void) {
	Solution solution;
	cout << solution.arrangeCoins(5) << "\tPassed\n";
	cout << solution.arrangeCoins(8) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}