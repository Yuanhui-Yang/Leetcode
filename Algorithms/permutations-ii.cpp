// 47. Permutations II
// https://leetcode.com/problems/permutations-ii/

/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
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
		if (result) {
			int j = n - 1;
			while (j > i and nums[j] <= nums[i]) {
				j--;
			}
			swap(nums[j], nums[i]);
		}
		reverse(next(begin(nums), i + 1), end(nums));
		return result;
	}
};

int main(void) {
	Solution solution;

	vector<int> nums;
	vector<vector<int>> answer, result;

	nums = {1, 1, 2};
	answer = {{1, 1, 2}, {1, 2, 1}, {2, 1, 1}};
	sort(begin(answer), end(answer));
	result = solution.permuteUnique(nums);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}