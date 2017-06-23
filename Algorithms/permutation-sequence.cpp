// 60. Permutation Sequence
// https://leetcode.com/problems/permutation-sequence/

/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		--k;
		vector<int> v(10, 0);
		v[0] = 1;
		for (int i = 1; i <= 9; ++i) {
			v[i] = i * v[i - 1];
		}
		vector<bool> w(n + 1, true);
		string result(n, '0');
		for (int i = 0; i < n; ++i) {
			int j = n - i - 1, l = k / v[j] + 1, m = 1;
			while (l-- > 0) {
				while (m < n and !w[m]) {
					++m;
				}
				++m;
			}
			--m;
			result[i] = '0' + m;
			w[m] = false;
			k %= v[j];
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	int n, k;
	string answer, result;

	n = 2;
	k = 1;
	answer = "12";
	result = solution.getPermutation(n, k);
	assert(answer == result);

	n = 2;
	k = 2;
	answer = "21";
	result = solution.getPermutation(n, k);
	assert(answer == result);

	n = 3;
	k = 2;
	answer = "132";
	result = solution.getPermutation(n, k);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}