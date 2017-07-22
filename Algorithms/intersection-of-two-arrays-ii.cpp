// 350. Intersection of Two Arrays II
// https://leetcode.com/problems/intersection-of-two-arrays-ii/

/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		int M = nums1.size(), N = nums2.size();
		if (M > N) {
			return intersect(nums2, nums1);
		}
		vector<int> result;
		sort(begin(nums1), end(nums1));
		sort(begin(nums2), end(nums2));
		int i = 0;
		while (i < M) {
			int x = i;
			while (i < M and nums1[i] == nums1[x]) {
				++i;
			}
			pair<vector<int>::iterator, vector<int>::iterator> p = equal_range(begin(nums2), end(nums2), nums1[x]);
			int y = distance(p.first, p.second);
			int z = min(i - x, y);
			while (z-- > 0) {
				result.push_back(nums1[x]);
			}
		}
		return result;
	}
};