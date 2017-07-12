// 231. Power of Two
// https://leetcode.com/problems/power-of-two/

/*
Given an integer, write a function to determine if it is a power of two.
*/

class Solution {
public:
	bool isPowerOfTwo(int n) {
		return n > 0 and !(n & (n - 1));
	}
};