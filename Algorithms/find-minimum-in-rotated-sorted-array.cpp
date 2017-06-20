// 153. Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.empty()) {
			return INT_MAX;
		}
		int n = nums.size(), i = 0, j = n - 1, result = nums.front();
		while (i + 1 < j) {
			int mid = i + (j - i) / 2;
			if (nums[mid] >= nums.front()) {
				i = mid;
			}
			else {
				result = min(result, nums[mid]);
				j = mid;
			}
		}
		result = min(result, min(nums[i], nums[j]));
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	int answer, result;

	nums = {4, 5, 6, 7, 0, 1, 2};
	answer = 0;
	result = solution.findMin(nums);
	assert(answer == result);

	nums = {2, 1};
	answer = 1;
	result = solution.findMin(nums);
	assert(answer == result);

	nums = {1, 2, 3};
	answer = 1;
	result = solution.findMin(nums);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}