// 172. Factorial Trailing Zeroes
// https://leetcode.com/problems/factorial-trailing-zeroes/

/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

class Solution {
public:
	int trailingZeroes(int n) {
		int m = log(n) / log(5), result = 0;
		for (int i = 1; i <= m; ++i) {
			result += n / pow(5, i);
		}
		return result;
	}
};