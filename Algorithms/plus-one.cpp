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
        int carry = 1, sz = digits.size(), i = sz - 1;
        while (i >= 0 or carry > 0) {
            if (i >= 0) {
                int value = digits[i] + carry;
                digits[i] = value % 10;
                carry = value / 10;
            }
            else {
                digits.insert(digits.begin(), carry);
                carry = 0;
            }
            --i;
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
