// 313. Super Ugly Number
// https://leetcode.com/problems/super-ugly-number/

/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
(4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
*/

class Solution {
public:
	int nthSuperUglyNumber(size_t n, vector<int>& primes) {
		sort(begin(primes), end(primes));
		size_t k = primes.size();
		vector<int> A(k, 0);
		vector<long long> B;
		while (B.size() < n) {
			if (B.empty()) {
				B.push_back(1LL);
				continue;
			}
			size_t i = 0;
			long long minVal = primes[i] * B[A[i]];
			for (size_t j = 1; j < k; ++j) {
				if (primes[j] * B[A[j]] < minVal) {
					i = j;
					minVal = primes[i] * B[A[i]];
				}
			}
			if (B.back() < minVal) {
				B.push_back(minVal);
			}
			++A[i];
		}
		return B.back();
	}
};