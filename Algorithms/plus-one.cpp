// 66. Plus One
// https://leetcode.com/problems/plus-one/

/*
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		size_t carry = 1, n = digits.size(), i = n - 1, base = 10;
		while (i != string::npos) {
			int x = digits[i] + carry;;
			digits[i] = x % base;
			carry = x / base;
			--i;
		}
		if (carry) {
			digits.insert(begin(digits), 1);
		}
		return digits;
	}
};

int main(void) {
	Solution solution;
	vector<int> digits, answer, result;

	digits = {9, 9, 9, 9};
	answer = {1, 0, 0, 0, 0};
	result = solution.plusOne(digits);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}