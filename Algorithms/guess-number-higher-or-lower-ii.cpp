// 375. Guess Number Higher or Lower II
// https://leetcode.com/problems/guess-number-higher-or-lower-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/51353/simple-dp-solution-with-explanation
// BEGIN: Top-down Approach
class Solution {
public:
	int getMoneyAmount(int n) {
		if (n <= 1) return 0;
		vector<vector<int>> OPT(n + 1, vector<int>(n + 1, 0));
		return this->getMoneyAmount(OPT, 1, n);
	}
private:
	int getMoneyAmount(vector<vector<int>>& OPT, int i, int j) {
		if (i >= j) return 0;
		if (OPT[i][j]) return OPT[i][j];
		int result = INT_MAX;
		for (int k = i; k <= j; k++)
			OPT[i][j] = result = min(result, k + max(this->getMoneyAmount(OPT, i, k - 1), this->getMoneyAmount(OPT, k + 1, j)));
		return result;
	}
};
// END: Top-down Approach

// BEGIN: Bottom-up Approach
// class Solution {
// public:
// 	int getMoneyAmount(int n) {
// 		if (n <= 1) return 0;
// 		vector<vector<int>> OPT(n + 1, vector<int>(n + 1, 0));
// 		for (int i = 1; i < n; i++) OPT[i][i + 1] = i;
// 		for (int i = 2; i <= n; i++) {
// 			for (int j = 0; i + j <= n; j++) {
// 				OPT[j][j + i] = INT_MAX;
// 				for (int k = j + 1; k < j + i; k++) {
// 					OPT[j][j + i] = min(OPT[j][j + i], k + max(OPT[j][k - 1], OPT[k + 1][i + j]));
// 				}
// 			}
// 		}
// 		return OPT[1][n];
// 	}
// };
// END: Bottom-up Approach
// END: https://discuss.leetcode.com/topic/51353/simple-dp-solution-with-explanation
int main(void) {
	Solution solution;
	for (int i = 0; i <= 100; i++) {
		cout << "n = " << i << " => " << solution.getMoneyAmount(i) << "\tPassed\n";
	}
	cout << "\nPassed All\n";
	return 0;
}