// 414. Third Maximum Number
// https://leetcode.com/problems/third-maximum-number/

/*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/

class Solution {
public:
	int thirdMax(vector<int>& nums) {
		array<int, 3> A;
		A[0] = -1;
		A[1] = -1;
		A[2] = -1;
		for (int sz = nums.size(), i = 0; i < sz; ++i) {
			if (A[0] >= 0 and nums[A[0]] == nums[i]) {
				continue;
			}
			if (A[1] >= 0 and nums[A[1]] == nums[i]) {
				continue;
			}
			if (A[2] >= 0 and nums[A[2]] == nums[i]) {
				continue;
			}
			if (A[0] < 0 or nums[A[0]] < nums[i]) {
				A[2] = A[1];
				A[1] = A[0];
				A[0] = i;
				continue;
			}
			if (A[1] < 0 or nums[A[1]] < nums[i]) {
				A[2] = A[1];
				A[1] = i;
				continue;
			}
			if (A[2] < 0 or nums[A[2]] < nums[i]) {
				A[2] = i;
				continue;
			}
		}
		return A[2] >= 0 ? nums[A[2]] : nums[A[0]];
	}
};