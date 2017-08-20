// 485. Max Consecutive Ones
// https://leetcode.com/problems/max-consecutive-ones/

/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
	The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
*/

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int sz = nums.size(), result = 0;
		for (int i = 0; i < sz; ++i) {
			if (nums[i] == 1) {
				int curr = 1;
				while (i + 1 < sz and nums[i + 1] == 1) {
					++i;
					++curr;
				}
				result = max(result, curr);
			}
		}
		return result;
	}
};