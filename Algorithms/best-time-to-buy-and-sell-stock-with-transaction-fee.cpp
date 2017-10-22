// 714. Best Time to Buy and Sell Stock with Transaction Fee
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

/*
Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Note:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sz = prices.size(), i;
        if (sz < 2) {
            return 0;
        }
        vector<int> A(sz, 0), B(sz, 0);
        A[0] = -prices[0];
        B[0] = 0;
        for (i = 1; i < sz; ++i) {
            A[i] = max(A[i - 1], B[i - 1] - prices[i]);
            B[i] = max(B[i- 1], A[i - 1] + prices[i] - fee);
        }
        return B[sz - 1];
    }
};

int main(void) {
    Solution solution;
    vector<int> prices;
    int fee, result;
    
    prices = {1, 3, 2, 8, 4, 9};
    fee = 2;
    result = solution.maxProfit(prices, fee);
    cout << result << '\n';
    
    return 0;
}