// 343. Integer Break
// https://leetcode.com/problems/integer-break/

/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int integerBreak(int n) {
		vector<int> OPT(max(n + 1, 3), 0);
		OPT[0] = 0;
		OPT[1] = 1;
		OPT[2] = 1;
		for (int i = 3; i <= n; ++i) {
			for (int j = 1; j < i; ++j) {
				OPT[i] = max(OPT[i], max(OPT[i - j], i - j) * j);
			}
		}
		return OPT[n];
	}
};

int main(void) {
	Solution solution;
	int n, answer, result;

	n = 2;
	answer = 1;
	result = solution.integerBreak(n);
	assert(answer == result);

	n = 10;
	answer = 36;
	result = solution.integerBreak(n);
	assert(answer == result);

	n = 3;
	answer = 2;
	result = solution.integerBreak(n);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}