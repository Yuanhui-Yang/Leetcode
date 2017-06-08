// 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int result = 0;
		for (int i = 0, n = nums.size(); i < n; ++i) {
			if (i > 0 and nums[i] == nums[i - 1]) {
				continue;
			}
			nums[result++] = nums[i];
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums, answer;
	int result;

	nums = {1, 1, 2};
	answer = {1, 2};
	result = solution.removeDuplicates(nums);
	assert(answer == vector<int>(begin(nums), next(begin(nums), result)));

	cout << "\nPassed All\n";
	return 0;
}