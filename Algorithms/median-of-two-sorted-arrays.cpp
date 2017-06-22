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
		size_t m = nums1.size(), n = nums2.size(), k = (m + n) / 2;
		return ((m + n) & 1) ? f(nums1, nums2, 0, 0, k + 1) : (f(nums1, nums2, 0, 0, k) + f(nums1, nums2, 0, 0, k + 1)) / 2.0;
	}
private:
	double f(vector<int>& nums1, vector<int>& nums2, int i, int j, int k) {
		int m = nums1.size(), n = nums2.size();
		if (m - i < n - j) {
			return f(nums2, nums1, j, i, k);
		}
		if (j == n) {
			return nums1[i + k - 1];
		}
		if (k == 1) {
			return min(nums1[i], nums2[j]);
		}
		int dy = min(n - j, k / 2);
		int dx = k - dy;
		int x = i + dx, y = j + dy;
		if (nums1[x - 1] < nums2[y - 1]) {
			return f(nums1, nums2, x, j, dy);
		}
		return f(nums1, nums2, i, y, dx);
	}
};

int main(void) {
	Solution solution;
	vector<int> nums1, nums2;
	double result, answer;

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