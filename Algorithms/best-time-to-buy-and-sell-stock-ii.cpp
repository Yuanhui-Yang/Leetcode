// 122. Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// https://discuss.leetcode.com/topic/726/is-this-question-a-joke
// http://blog.unieagle.net/2012/12/04/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Abest-time-to-buy-and-sell-stock-ii/
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
		for (int i = 0; i + 1 < n; i++) result += max(0, prices[i + 1] - prices[i]);
		return result;
	}
};
// class Solution {
// public:
// 	int maxProfit(const vector<int>& prices) {
// 		return this->maxProfit(prices.size(), prices);
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
	assert(7 == solution.maxProfit(prices));
	prices = {7, 6, 4, 3, 1};
	assert(0 == solution.maxProfit(prices));
	cout << "\nPassed All\n";
	return 0;
}