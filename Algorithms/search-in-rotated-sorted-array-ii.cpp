// 81. Search in Rotated Sorted Array II
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.empty()) {
			return false;
		}
		if (nums.front() == target) {
			return true;
		}
		int n = nums.size(), i = 0, j = n - 1;
		while (i + 1 < j and nums[i + 1] == nums[i]) {
			++i;
		}
		if (target > nums.front()) {
			while (i + 1 < j) {
				int mid = i + (j - i) / 2;
				if (nums[mid] <= nums.front()) {
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
				if (nums[mid] > nums.front()) {
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
		return nums[i] == target or nums[j] == target;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	int target;
	bool answer, result;

	nums = {1, 3, 1, 1, 1};
	target = 3;
	answer = true;
	result = solution.search(nums, target);
	assert(answer == result);

	nums = {4, 5, 6, 7, 4, 4, 4};
	target = 7;
	answer = true;
	result = solution.search(nums, target);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}