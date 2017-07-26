// 594. Longest Harmonious Subsequence
// https://leetcode.com/problems/longest-harmonious-subsequence/

/*
We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Note: The length of the input array will not exceed 20,000.
*/

class Solution {
public:
	int findLHS(vector<int>& nums) {
		unordered_multiset<int> A;
		int sz = nums.size(), result = 0;
		for (int i = 0; i < sz; ++i) {
			int x = A.count(nums[i] - 1);
			x = x == 0 ? 0 : x + 1 + A.count(nums[i]);
			int y = A.count(nums[i] + 1);
			y = y == 0 ? 0 : y + 1 + A.count(nums[i]);
			int cnt = max(x, y);
			result = max(result, cnt);
			A.insert(nums[i]);
		}
		return result;
	}
};