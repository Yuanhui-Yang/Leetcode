// 556. Next Greater Element III
// https://leetcode.com/problems/next-greater-element-iii/

/*
Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:
Input: 12
Output: 21
Example 2:
Input: 21
Output: -1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int nextGreaterElement(int n) {
		string s = to_string(n);
		bool l = nextPermutation(s);
		long long m = stoll(s);
		return (l and m >= 0 and m <= (long long)INT_MAX) ? m : -1; 
	}
private:
	bool nextPermutation(string& s) {
		if (s.empty()) {
			return "";
		}
		int n = s.size(), i = n - 2;
		while (i >= 0 and s[i] >= s[i + 1]) {
			--i;
		}
		bool result = (i >= 0);
		if (result) {
			int j = n - 1;
			while (j > i and s[j] <= s[i]) {
				--j;
			}
			swap(s[i], s[j]);
		}
		reverse(next(begin(s), i + 1), end(s));
		return result;
	}
};

int main(void) {
	Solution solution;
	int n, answer, result;

	n = 1999999999;
	answer = -1;
	result = solution.nextGreaterElement(n);
	assert(answer == result);

	n = 12;
	answer = 21;
	result = solution.nextGreaterElement(n);
	assert(answer == result);

	n = 21;
	answer = -1;
	result = solution.nextGreaterElement(n);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}