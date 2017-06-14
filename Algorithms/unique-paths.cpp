// 62. Unique Paths
// https://leetcode.com/problems/unique-paths/

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<int> OPT(m, 1);
		for (int i = n - 2; i >= 0; --i) {
			for (int j = m - 2; j >= 0; --j) {
				OPT[j] += OPT[j + 1];
			}
		}
		return OPT[0];
	}
};

int main(void) {
	Solution solution;
	int m, n, answer, result;

	m = 10;
	n = 10;
	answer = 48620;
	result = solution.uniquePaths(m, n);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}