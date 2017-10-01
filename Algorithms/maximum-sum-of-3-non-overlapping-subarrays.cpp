// 689. Maximum Sum of 3 Non-Overlapping Subarrays
// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/

/*
In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

Example:
Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
Note:
nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).
*/

#include <iostream>
#include <array>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		int sz = nums.size(), i = 0, a = 0, b = 0;
		if (k <= 0 or sz < 3 * k) {
			return {};
		}
		vector<int> A;
		a = 0;
		A.push_back(a);
		for (i = 0; i < sz; ++i) {
			a += nums[i];
			A.push_back(a);
		}
		array<vector<vector<int>>, 3> B;
		B[0].resize(sz - k + 1);
		B[1].resize(sz - 2 * k + 1);
		B[2].resize(sz - 3 * k + 1);
		B[0][sz - k] = {sz - k};
		for (i = sz - k - 1; i >= 0; --i) {
			a = f(A, k, i);
			b = f(A, k, B[0][i + 1][0]);
			if (a >= b) {
				B[0][i] = {i};
			}
			else {
				B[0][i] = B[0][i + 1];
			}
		}
		B[1][sz - 2 * k] = {sz - 2 * k, sz - k};
		for (i = sz - 2 * k - 1; i >= 0; --i) {
			a = f(A, k, i) + f(A, k, B[0][i + k][0]);
			b = f(A, k, B[1][i + 1][0]) + f(A, k, B[1][i + 1][1]);
			if (a >= b) {
				B[1][i] = {i, B[0][i + k][0]};
			}
			else {
				B[1][i] = B[1][i + 1];
			}
		}
		B[2][sz - 3 * k] = {sz - 3 * k, sz - 2 * k, sz - k};
		for (i = sz - 3 * k - 1; i >= 0; --i) {
			a = f(A, k, i) + f(A, k, B[1][i + k][0]) + f(A, k, B[1][i + k][1]);
			b = f(A, k, B[2][i + 1][0]) + f(A, k, B[2][i + 1][1]) + f(A, k, B[2][i + 1][2]);
			if (a >= b) {
				B[2][i] = {i, B[1][i + k][0], B[1][i + k][1]};
			}
			else {
				B[2][i] = B[2][i + 1];
			}
		}
		return B[2][0];
	}
private:
	int f(const vector<int> & A, const int k, const int start) {
		return A[start + k] - A[start];
	}
};

int main(void) {
	Solution solution;
	vector<int> nums, result;
	int k;
	
	nums = {1, 2, 1, 2, 6, 7, 5, 1};
	k = 2;
	result = solution.maxSumOfThreeSubarrays(nums, k);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';

	return 0;
}