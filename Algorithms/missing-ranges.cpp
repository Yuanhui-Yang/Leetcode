// 163. Missing Ranges
// https://leetcode.com/problems/missing-ranges/

/*
Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/

class Solution {
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		if (lower > upper) {
			return {};
		}
		vector<string> result;
		int n = nums.size(), i = 0;
		while (i < n and nums[i] < lower) {
			++i;
		}
		if (i >= n) {
			result.push_back(lower == upper ? to_string(lower) : to_string(lower) + "->" + to_string(upper));
			return result;
		}
		if (nums[i] > lower) {
			result.push_back((long)lower + 1 == (long)nums[i] ? to_string(lower) : to_string(lower) + "->" + to_string((long)nums[i] - 1));
			lower = nums[i];
		}
		++i;
		while (i < n and nums[i] <= upper) {
			if ((long)lower + 1 < (long)nums[i]) {
				result.push_back((long)lower + 2 == (long)nums[i] ? to_string((long)lower + 1) : to_string((long)lower + 1) + "->" + to_string((long)nums[i] - 1));
			}
			lower = nums[i];
			++i;
		}
		if (i >= n and lower < upper) {
			result.push_back((long)lower + 1 == upper ? to_string(upper) : to_string((long)lower + 1) + "->" + to_string(upper));
		}
		return result;
	}
};