// 673. Number of Longest Increasing Subsequence
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

/*
Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int sz = nums.size(), i = 0, j = 0, maxLen = 1, result = 1;
		vector<int> A(sz, 1), B(sz, 1);
		for (i = 1; i < sz; ++i) {
			for (j = 0; j < i; ++j) {
				if (nums[i] > nums[j]) {
					if (A[i] < A[j] + 1) {
						A[i] = A[j] + 1;
						B[i] = B[j];
					}
					else if (A[i] == A[j] + 1) {
						B[i] += B[j];
					}
				}
			}
			if (maxLen < A[i]) {
				result = B[i];
				maxLen = A[i];
			}
			else if (maxLen == A[i]) {
				result += B[i];
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	int result;
	
	nums = {1, 3, 5, 4, 7};
	result = solution.findNumberOfLIS(nums);
	cout << result << '\n';

	nums = {2, 2, 2, 2, 2};
	result = solution.findNumberOfLIS(nums);
	cout << result << '\n';

	nums = {1, 2, 4, 3, 5, 4, 7, 2};
	result = solution.findNumberOfLIS(nums);
	cout << result << '\n';
	
	return 0;
}