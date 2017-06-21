// 300. Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/

/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> v;
		for (const auto &i : nums) {
			vector<int>::iterator it = lower_bound(begin(v), end(v), i);
			if (it == end(v)) {
				v.push_back(i);
			}
			else {
				*it = i;
			}
		}
		return v.size();
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	int answer, result;

	nums = {10, 9, 2, 5, 3, 7, 101, 18};
	answer = 4;
	result = solution.lengthOfLIS(nums);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}