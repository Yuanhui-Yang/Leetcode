// 487. Max Consecutive Ones II
// https://leetcode.com/problems/max-consecutive-ones-ii/

/*
Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

Example 1:
Input: [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
	After flipping, the maximum number of consecutive 1s is 4.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
Follow up:
What if the input numbers come in one by one as an infinite stream? In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently?
*/

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int sz = nums.size(), result = 0;
		array<int, 2> prev({-1, -1});
		for (int i = 0; i < sz; ++i) {
			if (nums[i] == 1) {
				int j = i;
				while (i < sz and nums[i] == 1) {
					++i;
				}
				if (j == 0 and i == sz) {
					result = max(result, i - j);
				}
				else {
					result = max(result, i + 1 - j);
				}
				if (prev[0] >= 0 and j - prev[1] == 1) {
					result = max(result, i - prev[0]);
				}
				prev[0] = j;
				prev[1] = i;
			}
			else {
				result = max(result, 1);
			}
		}
		return result;
	}
};