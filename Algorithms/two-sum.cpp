// 1. Two Sum
// https://leetcode.com/problems/two-sum/

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> h;
		for (int i = 0, n = nums.size(); i < n; ++i) {
			if (h.count(target - nums[i])) {
				return {h[target - nums[i]], i};
			}
			h[nums[i]] = i;
		}
		return {};
	}
};

int main(void) {
	Solution solution;
	vector<int> nums, result, answer;
	int target = 0;

	nums = {2, 7, 11, 15};
	target = 9;
	answer = {0, 1};
	result = solution.twoSum(nums, target);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}