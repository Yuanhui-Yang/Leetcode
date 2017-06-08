// 561. Array Partition I
// https://leetcode.com/problems/array-partition-i/

/*
Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4.
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		int result = 0;
		for (int i = 0, n = nums.size(); i < n; ++i) {
			if (i % 2 == 0) {
				result += nums[i];
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	int answer, result;

	nums = {1, 4, 3, 2};
	answer = 4;
	result = solution.arrayPairSum(nums);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}