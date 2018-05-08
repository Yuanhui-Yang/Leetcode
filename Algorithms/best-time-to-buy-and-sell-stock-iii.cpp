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
        int sz = prices.size();
        if (sz <= 1) {
            return 0;
        }
        vector<int> nohold(3, 0), hold(3, INT_MIN);
        for (const auto & price : prices) {
            for (int i = 1; i < 3; ++i) {
                hold[i] = max(hold[i], nohold[i - 1] - price);
                nohold[i] = max(nohold[i], hold[i] + price);
            }
        }
        return nohold.back();
    }
};
