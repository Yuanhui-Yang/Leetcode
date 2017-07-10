// 229. Majority Element II
// https://leetcode.com/problems/majority-element-ii/

/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
*/

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int x1 = 0, x2 = 0, c1 = 0, c2 = 0, n = nums.size();
		for (const auto & i : nums) {
			if (c1 > 0 and i == x1) {
				++c1;
				continue;
			}
			if (c2 > 0 and i == x2) {
				++c2;
				continue;
			}
			if (c1 == 0) {
				x1 = i;
				++c1;
				continue;
			}
			if (c2 == 0) {
				x2 = i;
				++c2;
				continue;
			}
			--c1;
			--c2;
		}
		vector<int> result;
		if (c1 > 0) {
			c1 = 0;
			for (const auto & i : nums) {
				c1 += i == x1;
			}
			if (c1 > n / 3) {
				result.push_back(x1);
			}
		}
		if (c2 > 0) {
			c2 = 0;
			for (const auto & i : nums) {
				c2 += i == x2;
			}
			if (c2 > n / 3) {
				result.push_back(x2);
			}
		}
		return result;
	}
};