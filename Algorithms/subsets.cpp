// 78. Subsets
// https://leetcode.com/problems/subsets/

/*
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> v;
		dfs(result, v, nums, 0);
		return result;
	}
private:
	void dfs(vector<vector<int>>& result, vector<int>& v, vector<int>& nums, int i) {
		result.push_back(v);
		for (int j = i, n = nums.size(); j < n; j++) {
			v.push_back(nums[j]);
			dfs(result, v, nums, j + 1);
			v.pop_back();
		}
	} 
};

int main(void) {
	Solution solution;
	vector<int> nums;
	vector<vector<int>> result, answer;

	nums = {1, 2, 3};
	answer = {{3}, {1}, {2}, {1, 2, 3}, {1, 3}, {2, 3}, {1, 2}, {}};
	sort(begin(answer), end(answer));
	result = solution.subsets(nums);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}