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
		if (t == 0) {
			return unordered_set<int>(begin(nums), end(nums)).size() < nums.size();
		}
		pair<vector<int>::iterator, vector<int>::iterator> p = minmax_element(begin(nums), end(nums));
		long minVal = *p.first, maxVal = *p.second;
		long m = nums.size(), n = (maxVal - minVal) / t + 1;
		unordered_map<long, long> dict;
		for (long i = 0; i < m; ++i) {
			if (i > k) {
				dict.erase(f1(nums[i - k - 1], minVal, t));
			}
			long id = f1(nums[i], minVal, t);
			if (dict.count(id) and f2(nums[dict[id]], nums[i]) <= t) {
				return true;
			}
			if (dict.count(id - 1) and f2(nums[dict[id - 1]], nums[i]) <= t) {
				return true;
			}
			if (dict.count(id + 1) and f2(nums[dict[id + 1]], nums[i]) <= t) {
				return true;
			}
			dict[id] = i;
		}
		return false;
	}
private:
	long f1(long val, long minVal, long t) {
		return (val - minVal) / t;
	}
	long f2(long a, long b) {
		return a < b ? b - a : a - b;
	}
};

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