// 172. Factorial Trailing Zeroes
// https://leetcode.com/problems/factorial-trailing-zeroes/

/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

class Solution {
public:
	int trailingZeroes(int n) {
		int result = 0;
		for (int i = 1, j = log(n) / log(5), k = 5; i <= j; ++i, k *= 5) {
			result += n / k;
		}
		return result;
	}
};

class Solution {
public:
	int trailingZeroes(int n) {
		int result = 0;
		for (int i = 1, j = log(n) / log(5); i <= j; ++i) {
			result += n / pow(5, i);
		}
		return result;
	}
};