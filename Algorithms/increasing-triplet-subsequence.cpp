// 334. Increasing Triplet Subsequence
// https://leetcode.com/problems/increasing-triplet-subsequence/

/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int a = INT_MAX, b = INT_MAX;
		for (const auto & i : nums) {
			if (i <= a) {
				a = i;
			}
			else if (i <= b) {
				b = i;
			}
			else {
				return true;
			}
		}
		return false;
	}
};