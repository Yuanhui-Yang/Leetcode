// 265. Paint House II
// https://leetcode.com/problems/paint-house-ii/

/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?
*/

class Solution {
public:
	int minCostII(vector<vector<int>>& costs) {
		int n = costs.size(), k = n == 0 ? 0 : costs[0].size();
		if (n == 0 or k == 0) {
			return 0;
		}
		if (n == 1) {
			return *min_element(begin(costs[0]), end(costs[0]));
		}
		if (k == 1) {
			return 0;
		}
		array<int, 3> curr({-1, 0, 0});
		for (int i = 0; i < n; ++i) {
			f(curr, costs[i]);
		}
		return curr[1];
	}
private:
	void f(array<int, 3> & curr, const vector<int> & v) {
		array<int, 3> next;
		next.fill(-1);
		for (int k = v.size(), j = 0; j < k; ++j) {
			int val = (j == curr[0] ? curr[2] : curr[1]) + v[j];
			if (next[1] < 0) {
				next[0] = j;
				next[1] = val;
			}
			else if (next[2] < 0) {
				if (val < next[1]) {
					next[2] = next[1];
					next[1] = val;
					next[0] = j;
				}
				else {
					next[2] = val;
				}
			}
			else if (val < next[1]) {
				next[2] = next[1];
				next[1] = val;
				next[0] = j;
			}
			else if (val < next[2]) {
				next[2] = val;
			}
		}
		curr = next;
	}
};

class Solution {
public:
	int minCostII(vector<vector<int>>& costs) {
		int n = costs.size(), k = n == 0 ? 0 : costs[0].size();
		if (n == 0 or k == 0) {
			return 0;
		}
		if (n == 1) {
			return *min_element(begin(costs[0]), end(costs[0]));
		}
		if (k == 1) {
			return 0;
		}
		array<int, 3> curr;
		curr.fill(-1);
		for (int j = 0; j < k; ++j) {
			int val = costs[0][j];
			if (curr[1] == -1) {
				curr[0] = j;
				curr[1] = val;
			}
			else if (curr[2] == -1) {
				if (val < curr[1]) {
					curr[2] = curr[1];
					curr[0] = j;
					curr[1] = val;
				}
				else {
					curr[2] = val;
				}
			}
			else if (val < curr[1]) {
				curr[2] = curr[1];
				curr[0] = j;
				curr[1] = val;
			}
			else if (val < curr[2]) {
				curr[2] = val;
			}
		}
		for (int i = 1; i < n; ++i) {
			int nextFirstVal = -1, nextFirstId = -1, nextSecondVal = -1;
			for (int j = 0; j < k; ++j) {
				int val = costs[i][j] + (j == curr[0] ? curr[2] : curr[1]);
				if (nextFirstVal == -1) {
					nextFirstVal = val;
					nextFirstId = j;
				}
				else if (nextSecondVal == -1) {
					if (val < nextFirstVal) {
						nextSecondVal = nextFirstVal;
						nextFirstVal = val;
						nextFirstId = j;
					}
					else {
						nextSecondVal = val;
					}
				}
				else if (val < nextFirstVal) {
					nextSecondVal = nextFirstVal;
					nextFirstVal = val;
					nextFirstId = j;
				}
				else if (val < nextSecondVal) {
					nextSecondVal = val;
				}
			}
			curr[1] = nextFirstVal;
			curr[0] = nextFirstId;
			curr[2] = nextSecondVal;
		}
		return curr[1];
	}
};