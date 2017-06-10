// 461. Hamming Distance
// https://leetcode.com/problems/hamming-distance/

/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int hammingDistance(int x, int y) {
		int result = 0, n = x ^ y;
		while (n) {
			++result;
			n &= n - 1;
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	int x, y, answer, result;

	x = 1;
	y = 4;
	answer = 2;
	result = solution.hammingDistance(x, y);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}