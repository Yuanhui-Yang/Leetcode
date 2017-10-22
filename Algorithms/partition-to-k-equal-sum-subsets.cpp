// 698. Partition to K Equal Sum Subsets
// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

/*
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:
Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

class Solution {
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int sz = nums.size(), i, sum = accumulate(begin(nums), end(nums), 0);
		if (sz < k or sum % k != 0) {
			return false;
		}
		sort(begin(nums), end(nums), greater<int>());
		vector<int> A(k, 0);
		return f1(nums, 0, A, sum / k);
	}
private:
	bool f1(const vector<int>& nums, const int start, vector<int> & A, const int target) {
		int k = A.size(), i, sz = nums.size();
		if (start == sz) {
			for (const auto & i : A) {
				if (i != target) {
					return false;
				}
			}
			return true;
		}
		for (i = 0; i < k; ++i) {
			if (A[i] + nums[start] <= target) {
				A[i] += nums[start];
				if (f1(nums, start + 1, A, target)) {
					return true;
				}
				A[i] -= nums[start];
			}
		}
		return false;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	int k;
	bool result;
	
	nums = {4, 3, 2, 3, 5, 2, 1};
	k = 4;
	result = solution.canPartitionKSubsets(nums, k);
	cout << boolalpha << result << '\n';

	return 0;
}