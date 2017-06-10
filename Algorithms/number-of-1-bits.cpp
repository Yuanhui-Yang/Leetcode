// 191. Number of 1 Bits
// https://leetcode.com/problems/number-of-1-bits/

/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int result = 0;
		while (n) {
			++result;
			n &= n - 1;
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	uint32_t n;
	int answer, result;

	n = 11;
	answer = 3;
	result = solution.hammingWeight(n);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}