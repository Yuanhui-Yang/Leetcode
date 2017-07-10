// 169. Majority Element
// https://leetcode.com/problems/majority-element/

/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int x = 0, cnt = 0;
		for (const auto & i : nums) {
			if (cnt == 0) {
				x = i;
				++cnt;
			}
			else if (i == x) {
				++cnt;
			}
			else {
				--cnt;
			}
		}
		return x;
	}
};