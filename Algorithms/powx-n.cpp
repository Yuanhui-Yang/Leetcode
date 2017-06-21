// 50. Pow(x, n)
// https://leetcode.com/problems/powx-n/

/*
Implement pow(x, n).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		return f(x, n);
	}
private:
	long double f(long double x, long long n) {
		if (x == 0 or n == 1) {
			return x;
		}
		if (x == 1 or n == 0) {
			return 1;
		}
		if (n < 0) {
			return 1 / f(x, -n);
		}
		long double y = f(x, n / 2);
		y *= y;
		return (n & 1) ? x * y : y;
	}
};

int main(void) {
	Solution solution;
	double x, answer, result;
	int n;

	x = 2.00000;
	n = -2147483648;
	answer = 0;
	result = solution.myPow(x, n);
	assert(fabs(answer - result) < numeric_limits<double>::epsilon());

	cout << "\nPassed All\n";
	return 0;
}