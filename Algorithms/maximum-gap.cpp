// 164. Maximum Gap
// https://leetcode.com/problems/maximum-gap/

/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) {
			return 0;
		}
		int minVal = nums[0], maxVal = nums[0];
		for (int i = 1; i < n; ++i) {
			minVal = min(minVal, nums[i]);
			maxVal = max(maxVal, nums[i]);
		}
		if (minVal == maxVal) {
			return 0;
		}
		if (n == 2) {
			return maxVal - minVal;
		}
		double delta = double(maxVal - minVal) / double(n - 1);
		vector<array<int, 2>> V(n, array<int, 2>({INT_MAX, INT_MIN}));
		for (const auto & i : nums) {
			int id = (i - minVal) / delta;
			V[id][0] = min(V[id][0], i);
			V[id][1] = max(V[id][1], i);
		}
		int result = 0, prev = INT_MAX;
		for (const auto & i : V) {
			if (i[0] == INT_MAX and i[1] == INT_MIN) {
				continue;
			}
			if (prev == INT_MAX) {
				result = max(result, i[1] - i[0]);
			}
			else {
				result = max(result, i[1] - i[0]);
				result = max(result, i[0] - prev);
			}
			prev = i[1];
		}
		return result;
	}
};