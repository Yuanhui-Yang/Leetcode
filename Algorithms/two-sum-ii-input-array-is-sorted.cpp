// 167. Two Sum II - Input array is sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int n = numbers.size(), i = 0, j = n - 1;
		while (i < j) {
			int sum = numbers[i] + numbers[j];
			if (sum == target) {
				return {1 + i, 1 + j};
			}
			if (sum < target) {
				++i;
				continue;
			}
			if (sum > target) {
				--j;
				continue;
			}
		}
		return {};
	}
};

int main(void) {
	Solution solution;
	vector<int> numbers, answer, result;
	int target;

	numbers = {2, 7, 11, 15};
	target = 9;
	answer = {1, 2};
	result = solution.twoSum(numbers, target);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}