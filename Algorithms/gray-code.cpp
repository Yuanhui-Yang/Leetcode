// 89. Gray Code
// https://leetcode.com/problems/gray-code/

/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> result;
		for (int i = 0, j = 1 << n; i < j; ++i) {
			result.push_back(i ^ (i >> 1));
		}
		return result;
	}
};

// class Solution {
// public:
// 	vector<int> grayCode(int n) {
// 		vector<int> result = {0};
// 		while (n-- > 0) {
// 			for (int m = result.size(), i = m - 1; i >= 0; --i) {
// 				result.push_back(m | result[i]);
// 			}
// 		} 
// 		return result;
// 	}
// };

int main(void) {
	Solution solution;
	int n;
	vector<int> answer, result;

	n = 0;
	answer = {0};
	result = solution.grayCode(n);
	assert(answer == result);

	n = 1;
	answer = {0, 1};
	result = solution.grayCode(n);
	assert(answer == result);

	n = 2;
	answer = {0, 1, 3, 2};
	result = solution.grayCode(n);
	assert(answer == result);

	n = 3;
	answer = {0, 1, 3, 2, 6, 7, 5, 4};
	result = solution.grayCode(n);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}