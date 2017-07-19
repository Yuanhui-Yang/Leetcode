// 256. Paint House
// https://leetcode.com/problems/paint-house/

/*
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.
*/

class Solution {
public:
	int minCost(vector<vector<int>>& costs) {
		if (costs.empty()) {
			return 0;
		}
		int n = costs.size();
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < 3; ++j) {
				int minVal = INT_MAX;
				for (int k = 1; k < 3; ++k) {
					minVal = min(minVal, costs[i - 1][(j + k) % 3]);
				}
				costs[i][j] += minVal;
			}
		}
		return min(costs[n - 1][0], min(costs[n - 1][1], costs[n - 1][2]));
	}
};