// 27. Remove Element
// https://leetcode.com/problems/remove-element/

/*
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int result = 0;
		for (int i = 0, n = nums.size(); i < n; ++i) {
			if (nums[i] != val) {
				nums[result++] = nums[i];
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums, answer;
	int val, result;

	nums = {3, 2, 2, 3};
	val = 3;
	answer = {2, 2};
	sort(begin(answer), end(answer));
	result = solution.removeElement(nums, val);
	sort(begin(nums), next(begin(nums), result));
	assert(answer == vector<int>(begin(nums), next(begin(nums), result)));

	cout << "\nPassed All\n";
	return 0;
}