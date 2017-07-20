// 322. Coin Change
// https://leetcode.com/problems/coin-change/

/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
*/

class Solution {
public:
	int coinChange(vector<int>& coins, long amount) {
		vector<long> A(amount + 1L, -1L);
		A[0] = 0L;
		for (const auto & i : coins) {
			if (i <= amount) {
				A[i] = 1L;
			}
		}
		for (long i = 1L; i <= amount; ++i) {
			if (A[i] >= 0) {
				continue;
			}
			long minCnt = -1L;
			for (const auto & j : coins) {
				if (j < i and A[i - j] > 0L and (minCnt < 0L or minCnt > 1L + A[i - j])) {
					minCnt = 1L + A[i - j];
				}
			}
			A[i] = minCnt;
		}
		return A[amount];
	}
};