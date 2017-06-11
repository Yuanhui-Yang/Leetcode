// 29. Divide Two Integers
// https://leetcode.com/problems/divide-two-integers/

/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0) {
			return INT_MAX;
		}
		long long a = llabs((long long)dividend), b = llabs((long long)divisor), result = 0, sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
		while (a >= b) {
			long long c = b, d = 1;
			while (a >= (c << 1)) {
				c <<= 1;
				d <<= 1;
			}
			a -= c;
			result += d;
		}
		result *= sign;
		return (result < (long long)INT_MIN) ? INT_MIN : (result > (long long)INT_MAX) ? INT_MAX : result;
	}
};

int main(void) {
	Solution solution;
	int dividend, divisor, answer, result;

	dividend = -2147483647;
	divisor = -1;
	answer = 2147483647;
	result = solution.divide(dividend, divisor);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}