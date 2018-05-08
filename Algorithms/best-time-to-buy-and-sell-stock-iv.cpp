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
        int sz = prices.size();
        return k >= sz / 2 ? f1(prices) : f2(k, prices);
    }
private:
    int f1(vector<int> & prices) {
        int result = 0;
        for (int sz = prices.size(), i = 0; i + 1 < sz; ++i) {
            if (prices[i] < prices[i + 1]) {
                result += prices[i + 1] - prices[i];
            }
        }
        return result;
    }
    int f2(int k, vector<int>& prices) {
        vector<int> hold(k + 1, INT_MIN), nohold(k + 1, 0);
        for (const auto & price : prices) {
            for (int i = 1; i <= k; ++i) {
                hold[i] = max(hold[i], nohold[i - 1] - price);
                nohold[i] = max(nohold[i], hold[i] + price);
            }
        }
        return nohold.back();
    }
};
