// 201. Bitwise AND of Numbers Range
// https://leetcode.com/problems/bitwise-and-of-numbers-range/

/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		while (n != (m & n)) {
			n &= n - 1;
		}
		return n;
	}
};

int main(void) {
	Solution solution;
	int m, n, answer, result;

	m = 2;
	n = 3;
	answer = 2;
	result = solution.rangeBitwiseAnd(m, n);
	assert(answer == result);

	m = 5;
	n = 7;
	answer = 4;
	result = solution.rangeBitwiseAnd(m, n);
	assert(answer == result);

	m = 0;
	n = 2147483647;
	answer = 0;
	result = solution.rangeBitwiseAnd(m, n);
	assert(answer == result);

	m = 20000;
	n = 2147483647;
	answer = 0;
	result = solution.rangeBitwiseAnd(m, n);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}