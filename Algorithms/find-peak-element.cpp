// 162. Find Peak Element
// https://leetcode.com/problems/find-peak-element/

/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ? num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -?.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.
*/

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int n = nums.size(), i = 0, j = n;
		while (i < j) {
			int k = i + (j - i) / 2;
			if (k + 1 < n and nums[k] < nums[k + 1]) {
				i = k + 1;
			}
			else {
				j = k;
			}
		}
		return i;
	}
};

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.empty()) {
			return -1;
		}
		if (nums.size() == 1) {
			return 0;
		}
		int n = nums.size(), i = 0, j = n - 1;
		if (nums[0] > nums[1]) {
			return 0;
		}
		if (nums[n - 2] < nums[n - 1]) {
			return n - 1;
		}
		while (i + 1 < j) {
			int k = i + (j - i) / 2;
			if (nums[k] < nums[k + 1]) {
				i = k;
			}
			else {
				j = k;
			}
		}
		if (nums[i - 1] < nums[i] and nums[i] > nums[i + 1]) {
			return i;
		}
		return i + 1;
	}
};