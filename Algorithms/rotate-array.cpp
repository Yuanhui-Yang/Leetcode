// 189. Rotate Array
// https://leetcode.com/problems/rotate-array/

/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II
*/

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.empty()) {
			return;
		}
		k %= nums.size();
		if (k == 0) {
			return;
		}
		reverse(begin(nums), end(nums));
		reverse(begin(nums), next(begin(nums), k));
		reverse(next(begin(nums), k), end(nums));
	}
};