// 123. Best Time to Buy and Sell Stock III
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		vector<int> buys(3, INT_MIN), sells(3, 0);
		for (const auto &price : prices) {
			for (int i = 1; i <= 2; ++i) {
				sells[i] = max(sells[i], buys[i] + price);
				buys[i] = max(buys[i], sells[i - 1] - price);
			}
		}
		return sells[2];
	}
};