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
        int min1 = 0, idx1 = -1, min2 = 0;
        for (const auto & cost : costs) {
            int nmin1 = INT_MAX, nidx1 = -1, nmin2 = INT_MAX;
            for (int sz = cost.size(), i = 0; i < sz; ++i) {
                int sum = cost[i] + (i == idx1 ? min2 : min1);
                if (sum < nmin1) {
                    nmin2 = nmin1;
                    nmin1 = sum;
                    nidx1 = i;
                }
                else if (sum < nmin2) {
                    nmin2 = sum;
                }
            }
            min1 = nmin1;
            idx1 = nidx1;
            min2 = nmin2;
        }
        return min1;
    }
};
