// 368. Largest Divisible Subset
// https://leetcode.com/problems/largest-divisible-subset/

/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		sort(begin(nums), end(nums));
		int sz = nums.size(), i, j, maxLen = 0, maxIdx = -1;
		vector<int> A(sz), B(sz), result;
		for (i = sz - 1; i >= 0; --i) {
			A[i] = 1;
			B[i] = -1;
			for (j = i + 1; j < sz; ++j) {
				if (nums[j] % nums[i] == 0 and A[i] < 1 + A[j]) {
					A[i] = 1 + A[j];
					B[i] = j;
				}
			}
			if (maxLen < A[i]) {
				maxLen = A[i];
				maxIdx = i;
			}
		}
		while (maxIdx >= 0) {
			result.push_back(nums[maxIdx]);
			maxIdx = B[maxIdx];
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums, result;
	
	nums = {1, 2, 3};
	result = solution.largestDivisibleSubset(nums);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';

	nums = {1, 2, 4, 8};
	result = solution.largestDivisibleSubset(nums);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';
	
	return 0;
}