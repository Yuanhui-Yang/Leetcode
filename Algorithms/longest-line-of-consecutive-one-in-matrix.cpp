// 562. Longest Line of Consecutive One in Matrix
// https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/

/*
Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.

Example:
Input:
[[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]
Output: 3
Hint: The number of elements in the given matrix will not exceed 10,000.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int longestLine(vector<vector<int>>& M) {
		if (M.empty() or M.front().empty()) {
			return 0;
		}
		int p = M.size(), q = M.front().size(), result = 0;
		vector<vector<int>> h(p, vector<int>(q, 0)), v(h), d(h), a(h); 
		for (int i = 0; i < p; ++i) {
			for (int j = 0; j < q; ++j) {
				result = max(result, h[i][j] = j == 0 ? M[i][j] : (M[i][j] == 0 ? 0 : 1 + h[i][j - 1]));
				result = max(result, v[i][j] = i == 0 ? M[i][j] : (M[i][j] == 0 ? 0 : 1 + v[i - 1][j]));
				result = max(result, d[i][j] = (i == 0 or j == 0) ? M[i][j] : (M[i][j] == 0 ? 0 : 1 + d[i - 1][j - 1]));
				result = max(result, a[i][q - 1 - j] = (i == 0 or j == 0) ? M[i][q - 1 - j] : (M[i][q - 1 - j] == 0 ? 0 : 1 + a[i - 1][q - j]));
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<vector<int>> M;
	int answer, result;

	M = {{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 1}};
	answer = 3;
	result = solution.longestLine(M);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}