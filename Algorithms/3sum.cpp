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
		vector<vector<int>> result;
		sort(begin(nums), end(nums));
		for (int i = 0, n = nums.size(); i < n; i++) {
			int target = -nums[i];
			int left = i + 1;
			int right = n - 1;
			while (left < right) {
				int sum = nums[left] + nums[right];
				if (sum < target) {
					left++;
				}
				else if (sum > target) {
					right--;
				}
				else {
					vector<int> v;
					v.push_back(nums[i]);
					v.push_back(nums[left]);
					v.push_back(nums[right]);
					result.push_back(v);
					while (left < right and nums[left] == v[1]) {
						left++;
					}
					while (left < right and nums[right] == v[2]) {
						right--;
					}
				}
			}
			while (i + 1 < n and nums[i + 1] == nums[i]) {
				i++;
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