// 400. Nth Digit
// https://leetcode.com/problems/nth-digit/

/*
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/

class Solution {
public:
	int findNthDigit(int n) {
		int i = 0;
		while (n - 9 * pow(10, i) * (i + 1) > 0) {
			n -= 9 * pow(10, i) * (i + 1);
			++i;
		}
		int val = pow(10, i);
		val += (n - 1) / (i + 1);
		string s = to_string(val);
		n = (n - 1) % (i + 1);
		return s[n] - '0';
	}
};