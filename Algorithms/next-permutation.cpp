// 31. Next Permutation
// https://leetcode.com/problems/next-permutation/

/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size(), i = n - 2;
		while (i >= 0 and nums[i] >= nums[i + 1]) {
			i--;
		}
		if (i >= 0) {
			int j = n - 1;
			while (j > i and nums[j] <= nums[i]) {
				j--;
			}
			swap(nums[i], nums[j]);
		}
		reverse(next(begin(nums), i + 1), end(nums));
	}
};

int main(void) {
	Solution solution;
	vector<int> nums, answer;

	nums = {1, 2, 3};
	answer = {1, 3, 2};
	solution.nextPermutation(nums);
	assert(answer == nums);

	nums = {1, 2, 3};
	answer = {1, 3, 2};
	solution.nextPermutation(nums);
	assert(answer == nums);

	nums = {3, 2, 1};
	answer = {1, 2, 3};
	solution.nextPermutation(nums);
	assert(answer == nums);

	nums = {1, 1, 5};
	answer = {1, 5, 1};
	solution.nextPermutation(nums);
	assert(answer == nums);

	cout << "\nPassed All\n";
	return 0;
}