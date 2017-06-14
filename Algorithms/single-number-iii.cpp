// 260. Single Number III
// https://leetcode.com/problems/single-number-iii/

/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int r = accumulate(begin(nums), end(nums), 0, bit_xor<int>());
		r &= ~(r - 1);
		vector<int> result(2, 0);
		for (const auto &i : nums) {
			if (r & i) {
				result[0] ^= i;
			}
			else {
				result[1] ^= i;
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums, answer, result;

	nums = {1, 2, 1, 3, 2, 5};
	answer = {3, 5};
	sort(begin(answer), end(answer));
	result = solution.singleNumber(nums);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}