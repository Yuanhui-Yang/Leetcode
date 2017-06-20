// 41. First Missing Positive
// https://leetcode.com/problems/first-missing-positive/

/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			while (nums[i] != i + 1 and nums[i] - 1 >= 0 and nums[i] - 1 < n and nums[nums[i] - 1] != nums[i]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (i + 1 != nums[i]) {
				return i + 1;
			}
		}
		return n + 1;
	}
};


int main(void) {
	Solution solution;
	vector<int> nums;
	int answer, result;

	nums = {1, 1};
	answer = 2;
	result = solution.firstMissingPositive(nums);
	assert(answer == result);

	nums = {1, 2, 0};
	answer = 3;
	result = solution.firstMissingPositive(nums);
	assert(answer == result);

	nums = {3, 4, -1, 1};
	answer = 2;
	result = solution.firstMissingPositive(nums);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}