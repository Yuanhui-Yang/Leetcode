// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/

/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		sort(begin(nums1), end(nums1));
		sort(begin(nums2), end(nums2));
		int M = nums1.size(), N = nums2.size(), i = 0, j = 0;
		while (i < M and j < N) {
			if (nums1[i] < nums2[j]) {
				++i;
			}
			else if (nums1[i] > nums2[j]) {
				++j;
			}
			else {
				if (result.empty()) {
					result.push_back(nums1[i]);
				}
				else if (result.back() != nums1[i]) {
					result.push_back(nums1[i]);
				}
				++i;
				++j;
			}
		}
		return result;
	}
};