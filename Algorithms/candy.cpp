// 135. Candy
// https://leetcode.com/problems/candy/

/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

class Solution {
public:
	int candy(vector<int>& ratings) {
		if (ratings.empty()) {
			return 0;
		}
		int n = ratings.size(), result = 0;
		vector<int> x(n, 0), y(x);
		x.front() = 1;
		y.back() = 1;
		for (int i = 1; i < n; ++i) {
			x[i] = ratings[i] > ratings[i - 1] ? x[i - 1] + 1 : 1;
		}
		for (int i = n - 2; i >= 0; --i) {
			y[i] = ratings[i] > ratings[i + 1] ? y[i + 1] + 1 : 1;
		}
		for (int i = 0; i < n; ++i) {
			result += max(x[i], y[i]);
		}
		return result;
	}
};