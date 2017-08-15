// 327. Count of Range Sum
// https://leetcode.com/problems/count-of-range-sum/

/*
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ? j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.
*/

class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		long long result = 0, sz = nums.size(), sum = 0;
		if (sz == 0LL) {
			return result;
		}
		multiset<long long> A;
		A.insert(0LL);
		for (long long i = 0; i < sz; ++i) {
			sum += (long long)nums[i];
			long long a = sum - (long long)upper, b = sum - (long long)lower;
			multiset<long long>::iterator begin = A.lower_bound(a), end = A.upper_bound(b);
			result += distance(begin, end);
			A.insert(sum);
		}
		return result;
	}
};