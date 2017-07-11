// 220. Contains Duplicate III
// https://leetcode.com/problems/contains-duplicate-iii/

/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
*/

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, long k, long t) {
		if (nums.empty() or k <= 0 or t < 0) {
			return false;
		}
		multiset<long> s;
		for (long n = nums.size(), i = 0; i < n; ++i) {
			multiset<long>::iterator iter = s.lower_bound(nums[i] - t);
			if (iter != end(s) and *iter <= nums[i] + t) {
				return true;
			}
			if (i >= k) {
				s.erase(s.find(nums[i - k]));
			}
			s.insert(nums[i]);
		}
		return false;
	}
};