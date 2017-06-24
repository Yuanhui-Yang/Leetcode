// 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		long double c = sqrt(5), A = 0.5 - 0.1 * c, B = 0.5 + 0.1 * c, x = 0.5 - 0.5 * c, y = 0.5 + 0.5 * c;
		return A * pow(x, n) + B * pow(y, n);
	}
};

int main(void) {
	Solution solution;
	int n, answer, result;

	n = 1;
	answer = 1;
	result = solution.climbStairs(n);
	assert(answer == result);

	n = 2;
	answer = 2;
	result = solution.climbStairs(n);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}