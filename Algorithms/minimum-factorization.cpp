// 625. Minimum Factorization
// https://leetcode.com/problems/minimum-factorization/

/*
Given a positive integer a, find the smallest positive integer b whose multiplication of each digit equals to a.

If there is no answer or the answer is not fit in 32-bit signed integer, then return 0.

Example 1
Input:

48 
Output:
68
Example 2
Input:

15
Output:
35
*/

#include <iostream>
#include <climits>
#include <array>

using namespace std;

class Solution {
public:
	int smallestFactorization(int a) {
		if (a <= 0) {
			return 0;
		}
		if (a < 10) {
			return a;
		}
		array<int, 10> A;
		A.fill(0);
		int i;
		for (i = 9; i > 1; --i) {
			while (a % i == 0) {
				++A[i];
				a /= i;
			}
		}
		if (a != 1) {
			return 0;
		}
		long long b = 0;
		for (i = 2; i < 10; ++i) {
			while (A[i] > 0) {
				b = 10 * b + i;
				--A[i];
			}
		}
		return b > INT_MAX ? 0 : b;
	}
};

int main(void) {
	Solution solution;
	int a, b;
	
	a = 48;
	b = solution.smallestFactorization(a);
	cout << b << '\n';
	
	a = 15;
	b = solution.smallestFactorization(a);
	cout << b << '\n';

	a = 6000000;
	b = solution.smallestFactorization(a);
	cout << b << '\n';
	
	return 0;
}

#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int smallestFactorization(int a) {
		unordered_map<long long, long long> A;
		return f1(A, a);
	}
	long long f1(unordered_map<long long, long long> & A, const long long a) {
		if (a <= 0) {
			return 0;
		}
		if (a < 10) {
			return a;
		}
		if (A.count(a)) {
			return A[a];
		}
		long long b = sqrt(a), i, j, x, y, z;
		string s, t, u;
		z = INT_MAX;
		for (i = 2; i <= b; ++i) {
			if (a % i == 0) {
				j = a / i;
				x = f1(A, i);
				y = f1(A, j);
				if (x != 0 and y != 0) {
					s = to_string(x);
					t = to_string(y);
					u = s + t;
					z = min(z, stoll(u));   
				}
			}
		}
		return A[a] = (z == INT_MAX ? 0 : z);
	}
};

int main(void) {
	Solution solution;
	int a, b;
	
	a = 48;
	b = solution.smallestFactorization(a);
	cout << b << '\n';
	
	a = 15;
	b = solution.smallestFactorization(a);
	cout << b << '\n';

	a = 6000000;
	b = solution.smallestFactorization(a);
	cout << b << '\n';
	
	return 0;
}