// 377. Combination Sum IV
// https://leetcode.com/problems/combination-sum-iv/

/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
*/

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		if (nums.empty()) {
			return 0;
		}
		sort(begin(nums), end(nums));
		int M = max(target, nums.back());
		vector<int> A(M + 1, 0);
		A[0] = 1;
		for (int i = 1; i <= M; ++i) {
			vector<int>::iterator it = upper_bound(begin(nums), end(nums), i);
			int N = distance(begin(nums), it);
			for (int j = 0; j < N; ++j) {
				A[i] += A[i - nums[j]];
			}
		}
		return A[target];
	}
};