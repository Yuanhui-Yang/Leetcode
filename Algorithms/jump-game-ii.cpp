// 45. Jump Game II
// https://leetcode.com/problems/jump-game-ii/

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int result = 0, i = 0, n = nums.size();
		while (i + 1 < n) {
			int j = i + nums[i];
			if (i + nums[i] + 1 < n) {
				for (int k = 1; k <= nums[i]; ++k) {
					if (i + k + nums[i + k] > j + nums[j]) {
						j = i + k;
					}
				}
			}
			i = j;
			++result;
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	int answer, result;

	nums = {2, 3, 1, 1, 4};
	answer = 2;
	result = solution.jump(nums);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}