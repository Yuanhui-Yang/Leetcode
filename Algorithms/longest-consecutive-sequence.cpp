// 128. Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/

/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int result = 0;
		unordered_map<int, int> h;
		for (const auto & i : nums) {
			if (h.count(i)) {
				continue;
			}
			int left = h.count(i - 1) ? h[i - 1] : 0;
			int right = h.count(i + 1) ? h[i + 1] : 0;
			int sum = 1 + left + right;
			result = max(result, sum);
			h[i] = sum;
			h[i - left] = sum;
			h[i + right] = sum;
		}
		return result;
	}
};