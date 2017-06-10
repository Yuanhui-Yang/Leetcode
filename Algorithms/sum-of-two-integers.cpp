// 371. Sum of Two Integers
// https://leetcode.com/problems/sum-of-two-integers/

/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		while (b) {
			int c = a;
			a = c ^ b;
			b = (c & b) << 1;
		}
		return a;
	}
};

int main(void) {
	Solution solution;
	int a, b, answer, result;

	a = 1;
	b = 2;
	answer = 3;
	result = solution.getSum(a, b);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}