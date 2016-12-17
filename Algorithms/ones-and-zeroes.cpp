// 474. Ones and Zeroes
// https://leetcode.com/problems/ones-and-zeroes/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		if (strs.empty()) return 0;
		const int strs_len = strs.size();
		vector<vector<int>> OPT(m + 1, vector<int>(n + 1, 0));
		vector<int> zeroes(strs_len, 0);
		vector<int> ones(strs_len, 0);
		for (int i = 0; i < strs_len; i++) {
			for (const auto&j : strs[i]) {
				zeroes[i] += j == '0';
				ones[i] += j == '1';
			}
		}
		for (int i = 0; i < strs_len; i++) {
			for (int j = m; j >= zeroes[i]; j--) {
				for (int k = n; k >= ones[i]; k--) {
					OPT[j][k] = max(OPT[j - zeroes[i]][k - ones[i]] + 1, OPT[j][k]);
				}
			}
		}
		return OPT[m][n];
	}
};
int main(void) {
	Solution solution;
	vector<string> strs;
	strs = {"10", "0001", "111001", "1", "0"};
	assert(4 == solution.findMaxForm(strs, 5, 3));
	strs = {"10", "0", "1"};
	assert(2 == solution.findMaxForm(strs, 1, 1));
	strs = {"0", "11", "1000", "01", "0", "101", "1", "1", "1", "0", "0", "0", "0", "1", "0", "0110101", "0", "11", "01", "00", "01111", "0011", "1", "1000", "0", "11101", "1", "0", "10", "0111"};
	assert(17 == solution.findMaxForm(strs, 9, 80));
	cout << "\nPassed All\n";
	return 0;
}