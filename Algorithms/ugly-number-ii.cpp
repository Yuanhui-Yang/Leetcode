// 264. Ugly Number II
// https://leetcode.com/problems/ugly-number-ii/

/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.
*/

class Solution {
public:
	int nthUglyNumber(size_t n) {
		array<int, 3> A;
		A[0] = 0;
		A[1] = 0;
		A[2] = 0;
		vector<long long> B;
		while (B.size() < n) {
			if (B.empty()) {
				B.push_back(1LL);
				continue;
			}
			long long x = B[A[0]] * 2LL, y = B[A[1]] * 3LL, z = B[A[2]] * 5LL, minVal = -1LL;
			if (x <= y and x <= z) {
				minVal = x;
				++A[0];
			}
			else if (y <= x and y <= z) {
				minVal = y;
				++A[1];
			}
			else if (z <= x and z <= y) {
				minVal = z;
				++A[2];
			}
			if (minVal != B.back()) {
				B.push_back(minVal);
			}
		}
		return B.back();
	}
};