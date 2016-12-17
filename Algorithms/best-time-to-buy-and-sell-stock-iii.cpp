// 123. Best Time to Buy and Sell Stock III
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/52580/java-solution-in-o-n-time-and-o-k-space
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		return this->maxProfit(2, prices);
	}
private:
	int maxProfit(int k, vector<int>& prices) {
		const int n = prices.size();
		if (n < 2) return 0;
		if (k >= n / 2) {
			int result = 0;
			for (int i = 1; i < n; i++) result += max(0, prices[i] - prices[i - 1]);
			return result;
		} 
		vector<int> buys(k + 1, INT_MIN);
		vector<int> sells(k + 1, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < k + 1; j++) {
				buys[j] = max(sells[j - 1] - prices[i], buys[j]);
				sells[j] = max(buys[j] + prices[i], sells[j]);
			}
		}
		return sells[k];
	}
};
// END: https://discuss.leetcode.com/topic/52580/java-solution-in-o-n-time-and-o-k-space
int main(void) {
	Solution solution;
	vector<int> prices;
	prices = {1, 2, 4};
	assert(3 == solution.maxProfit(prices));
	prices = {7, 6, 4, 3, 1};
	assert(0 == solution.maxProfit(prices));
	prices = {6, 1, 3, 2, 4, 7};
	assert(7 == solution.maxProfit(prices));
	prices = {3, 3, 5, 0, 0, 3, 1, 4};
	assert(6 == solution.maxProfit(prices));
	cout << "\nPassed All\n";
	return 0;
}