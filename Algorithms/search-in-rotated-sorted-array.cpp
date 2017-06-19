// 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty()) {
			return -1;
		}
		int n = nums.size(), i = 0, j = n - 1;
		if (target >= nums.front()) {
			while (i + 1 < j) {
				int mid = i + (j - i) / 2;
				if (nums[mid] < nums.front()) {
					j = mid;
				}
				else if (nums[mid] < target) {
					i = mid;
				}
				else {
					j = mid;
				}
			}
		}
		else {
			while (i + 1 < j) {
				int mid = i + (j - i) / 2;
				if (nums[mid] >= nums.front()) {
					i = mid;
				}
				else if (nums[mid] < target) {
					i = mid;
				}
				else {
					j = mid;
				}
			}
		}
		if (nums[i] == target) {
			return i;
		}
		if (nums[j] == target) {
			return j;
		}
		return -1;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	int target, answer, result;

	nums = {4, 5, 6, 7, 0, 1, 2};
	target = 0;
	answer = 4;
	result = solution.search(nums, target);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}