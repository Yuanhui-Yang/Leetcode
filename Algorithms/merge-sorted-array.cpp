// 88. Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1, k = m + n - 1;
		while (j >= 0) {
			nums1[k--] = (i >= 0 and nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
		}
	}
};

int main(void) {
	Solution solution;

	vector<int> nums1, nums2;
	int m, n;

	nums1 = {-1, 0, 0, 3, 3, 3, 0, 0, 0};
	m = 6;
	nums2 = {1, 2, 2};
	n = 3;
	solution.merge(nums1, m, nums2, n);
	assert(is_sorted(begin(nums1), next(begin(nums1), m + n)));

	nums1 = {1};
	m = 1;
	nums2 = {};
	n = 0;
	solution.merge(nums1, m, nums2, n);
	assert(is_sorted(begin(nums1), next(begin(nums1), m + n)));

	nums1 = {1, 2, 3, 0, 0, 0};
	m = 3;
	nums2 = {-3, -2, -1};
	n = 3;
	solution.merge(nums1, m, nums2, n);
	assert(is_sorted(begin(nums1), next(begin(nums1), m + n)));

	cout << "\nPassed All\n";
	return 0;
}