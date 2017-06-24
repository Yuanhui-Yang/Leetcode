// 80. Remove Duplicates from Sorted Array II
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int i = 0, j = 0, n = nums.size();
		while (i < n) {
			int k = i;
			while (i + 1 < n and nums[i + 1] == nums[i]) {
				++i;
			}
			int l = min(2, ++i - k);
			while (l--) {
				nums[j++] = nums[k];
			}
		}
		return j;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums, answer;
	int result;

	nums = {1, 1, 1, 2, 2, 3};
	answer = {1, 1, 2, 2, 3};
	result = solution.removeDuplicates(nums);
	assert(answer == vector<int>(begin(nums), next(begin(nums), result)));

	cout << "\nPassed All\n";
	return 0;
}