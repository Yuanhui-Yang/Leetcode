// 15. 3Sum
// https://leetcode.com/problems/3sum/

/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3) {
			return {};
		}
		vector<vector<int>> result;
		sort(begin(nums), end(nums));
		for (int i = 0, n = nums.size(); i + 3 <= n; i++) {
			if (i > 0 and nums[i] == nums[i - 1]) {
				continue;
			}
			if (nums[i] + nums[i + 1] + nums[i + 2] > 0) {
				break;
			}
			if (nums[i] + nums[n - 2] + nums[n - 1] < 0) {
				continue;
			}
			int left = i + 1, right = n - 1;
			while (left < right) {
				vector<int> v = {nums[i], nums[left], nums[right]};
				int sum = accumulate(begin(v), end(v), 0);
				if (sum < 0) {
					left++;
				}
				else if (sum > 0) {
					right--;
				}
				else {
					result.push_back(v);
					while (left < right and nums[left] == v[1]) {
						left++;
					}
					while (left < right and nums[right] == v[2]) {
						right--;
					}
				}
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	vector<vector<int>> result, answer;

	nums = {-1, 0, 1, 2, -1, -4};
	answer = {{-1, 0, 1}, {-1, -1, 2}};
	sort(begin(answer), end(answer));
	result = solution.threeSum(nums);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}