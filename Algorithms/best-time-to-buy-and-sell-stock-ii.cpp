// 122. Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int result = 0;
		for (int n = prices.size(), i = 0; i + 1 < n; ++i) {
			result += max(0, prices[i + 1] - prices[i]);
		}
		return result;
	}
};