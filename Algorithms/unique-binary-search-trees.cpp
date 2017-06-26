// 96. Unique Binary Search Trees
// https://leetcode.com/problems/unique-binary-search-trees/

/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numTrees(int n) {
		vector<vector<int>> M(n + 1, vector<int>(n + 1, 0));
		for (int l = 1; l <= n; ++l) {
			for (int i = 1; i + l <= n + 1; ++i) {
				int j = i + l - 1;
				for (int k = i; k <= j; ++k) {
					M[i][j] += (i >= k - 1 ? 1 : M[i][k - 1]) * (k + 1 >= j ? 1 : M[k + 1][j]);
				}
			}
		}
		return M[1][n];
	}
};

int main(void) {
	Solution solution;
	int n, answer, result;

	n = 3;
	answer = 5;
	result = solution.numTrees(n);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}