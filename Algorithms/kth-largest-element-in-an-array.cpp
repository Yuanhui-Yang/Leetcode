// 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/

/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		return f(nums, 0, nums.size() - 1, nums.size() - k);
	}
private:
	int f(vector<int>& nums, int p, int q, int k) {
		int pivot = nums[p], i = p + 1, j = q;
		while (i <= j) {
			if (nums[i] <= nums[p]) {
				++i;
				continue;
			}
			if (nums[j] > nums[p]) {
				--j;
				continue;
			}
			swap(nums[i++], nums[j--]);
		}
		swap(nums[p], nums[j]);
		if (k < j) {
			return f(nums, p, j - 1, k);
		}
		if (k > j) {
			return f(nums, j + 1, q, k);
		}
		return nums[k];
	}
};