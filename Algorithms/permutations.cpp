// 46. Permutations
// https://leetcode.com/problems/permutations/

/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		sort(begin(nums), end(nums));
		vector<vector<int>> result;
		do {
			result.push_back(nums);
		} while (nextPermutation(nums));
		return result;
	}
private:
	bool nextPermutation(vector<int>& nums) {
		int n = nums.size(), i = n - 2;
		while (i >= 0 and nums[i] >= nums[i + 1]) {
			i--;
		}
		bool result = (i >= 0);
		if (i >= 0) {
			int j = n - 1;
			while (j > i and nums[j] <= nums[i]) {
				j--;
			}
			swap(nums[i], nums[j]);
		}
		reverse(next(begin(nums), i + 1), end(nums));
		return result;
	}
};

int main(void) {
	Solution solution;

	vector<int> nums;
	vector<vector<int>> answer, result;

	nums = {0, -1, 1};
	answer = {{0, -1, 1}, {0, 1, -1}, {-1, 0, 1}, {-1, 1, 0}, {1, 0, -1}, {1, -1, 0}};
	sort(begin(answer), end(answer));
	result = solution.permute(nums);
	sort(begin(result), end(result));
	assert(answer == result);

	nums = {1, 2, 3};
	answer = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
	sort(begin(answer), end(answer));
	result = solution.permute(nums);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}