309. Best Time to Buy and Sell Stock with Cooldown
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if (sz < 2) {
            return 0;
        }
        int sell = 0, buy = -prices[0], prev_sell = sell;
        sell = max(sell, buy + prices[1]);
        buy = max(buy, -prices[1]);
        for (int i = 2; i < sz; ++i) {
            int prev_buy = buy;
            buy = max(buy, prev_sell - prices[i]);
            prev_sell = sell;
            sell = max(sell, prev_buy + prices[i]);
        }
        return sell;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if (sz < 2) {
            return 0;
        }
        vector<int> buy(sz, INT_MIN), sell(sz, 0);
        buy[0] = -prices[0];
        sell[0] = 0;
        buy[1] = max(buy[0], -prices[1]);
        sell[1] = max(sell[0], buy[0] + prices[1]);
        for (int i = 2; i < sz; ++i) {
            buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        return sell.back();
    }
};

int main(void) {
    Solution solution;
    vector<int> prices;
    int result;

    prices = {1, 2, 3, 0, 2};
    result = solution.maxProfit(prices);
    cout << result << '\n';

    return 0;
}
