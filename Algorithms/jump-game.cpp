// 55. Jump Game
// https://leetcode.com/problems/jump-game/

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size(), i = 0;
		while (i + 1 < n and i + nums[i] + 1 < n) {
			int k = i;
			for (int j = 1; j <= nums[i]; ++j) {
				if (i + j + nums[i + j] > k + nums[k]) {
					k = i + j;
				}
			}
			if (k == i) {
				return false;
			}
			i = k;
		}
		return true;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	bool answer, result;

	nums = {2, 3, 1, 1, 4};
	answer = true;
	result = solution.canJump(nums);
	assert(answer == result);

	nums = {3, 2, 1, 0, 4};
	answer = false;
	result = solution.canJump(nums);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}