// 188. Best Time to Buy and Sell Stock IV
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();
		if (k >= n / 2) {
			int result = 0;
			for (int i = 0; i + 1 < n; ++i) {
				result += max(0, prices[i + 1] - prices[i]);
			}
			return result;
		}
		vector<int> buys(k + 1, INT_MIN), sells(k + 1, 0);
		for (const auto &price : prices) {
			for (int i = 1; i <= k; ++i) {
				sells[i] = max(sells[i], buys[i] + price);
				buys[i] = max(buys[i], sells[i - 1] - price);
			}
		}
		return sells[k];
	}
};