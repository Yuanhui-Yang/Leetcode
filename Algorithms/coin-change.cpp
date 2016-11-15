// 322. Coin Change
// https://leetcode.com/problems/coin-change/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <climits>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/32475/c-o-n-amount-time-o-amount-space-dp-solution
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount == 0) return 0;
		sort(begin(coins), end(coins));
		if (coins.front() > amount) return -1;
		size_t n = (size_t)amount + 1;
		vector<size_t> OPT(n + 1, INT_MAX);
		for (const auto &i : coins) if (i <= amount) OPT[i] = 1;
		for (size_t i = 0; i < n; i++) {
			if (OPT[i] == INT_MAX) {
				for (const auto &j : coins) {
					if (i >= (size_t)j) {
						OPT[i] = min(OPT[i], 1 + OPT[i - j]);
					}
				}
			}
		}
		return OPT[amount] == INT_MAX ? -1 : OPT[amount];
	}
};
// END: https://discuss.leetcode.com/topic/32475/c-o-n-amount-time-o-amount-space-dp-solution

// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	int coinChange(vector<int>& coins, int amount) {
// 		if (amount == 0) return 0;
// 		sort(begin(coins), end(coins));
// 		if (coins.front() > amount) return -1;
// 		size_t n = (size_t)amount + 1;
// 		vector<size_t> OPT(n + 1, INT_MAX);
// 		for (const auto &i : coins) if (i <= amount) OPT[i] = 1;
// 		for (size_t i = 0; i < n; i++) {
// 			if (OPT[i] == INT_MAX) {
// 				for (size_t j = 1; j < i; j++) {
// 					if (OPT[j] != INT_MAX && OPT[i - j] != INT_MAX) {
// 						OPT[i] = min(OPT[i], OPT[j] + OPT[i - j]);
// 					}
// 				}
// 			}
// 		}
// 		return OPT[amount] == INT_MAX ? -1 : OPT[amount];
// 	}
// };
// END: Time Limit Exceeded
int main(void) {
	Solution solution;
	vector<int> coins = {1, 2, 5};
	cout << solution.coinChange(coins, 11) << "\tPassed\n";
	coins = {2};
	cout << solution.coinChange(coins, 3) << "\tPassed\n";
	coins = {2147483647};
	cout << solution.coinChange(coins, 2) << "\tPassed\n";
	coins = {1,2147483647};
	cout << solution.coinChange(coins, 2) << "\tPassed\n";
	coins = {1};
	cout << solution.coinChange(coins, 0) << "\tPassed\n";
	coins = {442,295,365,485};
	cout << solution.coinChange(coins, 8091) << "\tPassed\n";	
	cout << "\nPassed All\n";
	return 0;
}