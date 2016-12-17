// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// https://discuss.leetcode.com/topic/52580/java-solution-in-o-n-time-and-o-k-space/2
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if (n < 2) return 0;
        int result = 0;
        for (int i = 1, previous = prices[0]; i < n; i++) {
            int current = prices[i];
            result = max(result, current - previous);
            previous = min(previous, current);
        }
        return result;
    }
};
// class Solution {
// public:
// 	int maxProfit(const vector<int>& prices) {
// 		return this->maxProfit(1, prices);
// 	}
// private:
// 	int maxProfit(const size_t& k, const vector<int>& prices) {
// 		if (prices.empty()) return 0;
// 		if (k >= prices.size() / 2) {
// 			int result = 0;
// 			for (size_t i = 1; i < prices.size(); ++i) result += max(0, prices[i] - prices[i - 1]);
// 			return result;
// 		}
// 		vector<int> buy(k + 1, INT_MIN);
// 		vector<int> sell(k + 1, 0);
// 		for (const auto& price : prices) {
// 			for (size_t i = 1; i < k + 1; ++i) {
// 				buy[i] = max(buy[i], sell[i - 1] - price);
// 				sell[i] = max(sell[i], buy[i] + price);
// 			}
// 		}
// 		return sell[k];
// 	}
// };
int main(void) {
	Solution solution;
	vector<int> prices;
	prices = {7, 1, 5, 3, 6, 4};
	assert(5 == solution.maxProfit(prices));
	prices = {7, 6, 4, 3, 1};
	assert(0 == solution.maxProfit(prices));
	cout << "\nPassed All\n";
	return 0;
}