// 4. Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size(), l =  m + n;
		return l % 2 ? kth(l / 2 + 1, nums1, 0, m, nums2, 0, n) : (kth(l / 2, nums1, 0, m, nums2, 0, n) + kth(l / 2 + 1, nums1, 0, m, nums2, 0, n)) / 2.0;
	}
private:
	int kth(int k, vector<int>& nums1, int b1, int e1, vector<int>& nums2, int b2, int e2) {
		int m = e1 - b1, n = e2 - b2;
		if (m < n) {
			return kth(k, nums2, b2, e2, nums1, b1, e1);
		}
		if (n == 0) {
			return nums1[k - 1];
		}
		if (k == 1) {
			return min(nums1[b1], nums2[b2]);
		}
		int j = min(n, k / 2);
		int i = k - j;
		if (nums1[b1 + i - 1] > nums2[b2 + j - 1]) {
			return kth(k - j, nums1, b1, b1 + i, nums2, b2 + j, e2);
		}
		return kth(k - i, nums1, b1 + i, e1, nums2, b2, b2 + j);
	}
};

int main(void) {
	Solution solution;
	vector<int> nums1, nums2;
	double result = 0, answer = 0;

	nums1 = {3, 4, 5, 7, 8, 9, 10};
	nums2 = {1, 2, 6};
	answer = 5.5;
	result = solution.findMedianSortedArrays(nums1, nums2);
	assert(fabs(answer - result) < DBL_EPSILON);

	nums1 = {1, 5};
	nums2 = {2, 3, 4, 6, 7, 8, 9, 10};
	answer = 5.5;
	result = solution.findMedianSortedArrays(nums1, nums2);
	assert(fabs(answer - result) < DBL_EPSILON);

	nums1 = {1, 2};
	nums2 = {3, 4, 5, 6, 7, 8};
	answer = 4.5;
	result = solution.findMedianSortedArrays(nums1, nums2); 
	assert(fabs(answer - result) < DBL_EPSILON);

	nums1 = {1, 2, 6};
	nums2 = {3, 4, 5};
	answer = 3.5;
	result = solution.findMedianSortedArrays(nums1, nums2);
	assert(fabs(answer - result) < DBL_EPSILON);

	nums1 = {1, 4};
	nums2 = {2, 3, 5, 6};
	answer = 3.5;
	result = solution.findMedianSortedArrays(nums1, nums2);
	assert(fabs(answer - result) < DBL_EPSILON);

	nums1 = {1};
	nums2 = {2, 3, 4};
	answer = 2.5;
	result = solution.findMedianSortedArrays(nums1, nums2);
	assert(fabs(answer - result) < DBL_EPSILON);

	nums1 = {1, 3};
	nums2 = {2};
	answer = 2;
	result = solution.findMedianSortedArrays(nums1, nums2);
	assert(fabs(answer - result) < DBL_EPSILON);

	nums1 = {1, 2};
	nums2 = {3, 4};
	answer = 2.5;
	result = solution.findMedianSortedArrays(nums1, nums2);
	assert(fabs(answer - result) < DBL_EPSILON);

	cout << "\nPassed All\n";
	return 0;
}