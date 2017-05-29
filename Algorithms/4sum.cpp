// 18. 4Sum
// https://leetcode.com/problems/4sum/

/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		if (nums.size() < 4) {
			return {};
		}
		sort(begin(nums), end(nums));
		vector<vector<int>> result;
		for (int i = 0, n = nums.size(); i + 4 <= n; i++) {
			if (i > 0 and nums[i] == nums[i - 1]) {
				continue;
			}
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
				break;
			}
			if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) {
				continue;
			}
			for (int j = i + 1; j + 3 <= n; j++) {
				if (j > i + 1 and nums[j] == nums[j - 1]) {
					continue;
				}
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
					break;
				}
				if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) {
					continue;
				}
				int left = j + 1, right = n - 1;
				while (left < right) {
					vector<int> v = {nums[i], nums[j], nums[left], nums[right]};
					int sum = accumulate(begin(v), end(v), 0);
					if (sum < target) {
						left++;
					}
					else if (sum > target) {
						right--;
					}
					else {
						result.push_back(v);
						while (left < right and nums[left] == v[2]) {
							left++;
						}
						while (left < right and nums[right] == v[3]) {
							right--;
						}
					}
				}
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	int target;
	vector<int> nums;
	vector<vector<int>> result, answer;

	target = 0;
	nums = {0, 0, 0, 0};
	answer = {{0, 0, 0, 0}};
	sort(begin(answer), end(answer));
	result = solution.fourSum(nums, target);
	sort(begin(result), end(result));
	assert(answer == result);

	target = 0;
	nums = {-3, -2, -1, 0, 0, 1, 2, 3};
	answer = {{-3, -2, 2, 3}, {-3, -1, 1, 3}, {-3, 0, 0, 3}, {-3, 0, 1, 2}, {-2, -1, 0, 3}, {-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
	sort(begin(answer), end(answer));
	result = solution.fourSum(nums, target);
	sort(begin(result), end(result));
	assert(answer == result);

	target = 0;
	nums = {1, 0, -1, 0, -2, 2};
	answer = {{-1, 0, 0, 1}, {-2, -1, 1, 2}, {-2, 0, 0, 2}};
	sort(begin(answer), end(answer));
	result = solution.fourSum(nums, target);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}