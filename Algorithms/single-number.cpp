// 136. Single Number
// https://leetcode.com/problems/single-number/

/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		return accumulate(begin(nums), end(nums), 0, bit_xor<int>());
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	int answer, result;

	nums = {1, 1, 2, 2, 3};
	answer = 3;
	result = solution.singleNumber(nums);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}