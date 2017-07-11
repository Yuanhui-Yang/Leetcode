// 204. Count Primes
// https://leetcode.com/problems/count-primes/

/*
Description:

Count the number of prime numbers less than a non-negative number, n.
*/

class Solution {
public:
	int countPrimes(int n) {
		if (n < 2) {
			return 0;
		}
		vector<bool> A(n, true);
		A[0] = false;
		A[1] = false;
		for (int m = sqrt(n), i = 2; i <= m; ++i) {
			if (!A[i]) {
				continue;
			}
			for (int j = i * i; j < n; j += i) {
				A[j] = false;
			}
		}
		return count(begin(A), end(A), true);
	}
};