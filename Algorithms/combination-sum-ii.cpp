// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/

/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(begin(candidates), end(candidates));
		vector<vector<int>> result;
		vector<int> v;
		f(result, v, candidates, target, 0);
		return result;
	}
private:
	void f(vector<vector<int>>& result, vector<int>& v, vector<int>& candidates, int target, int i) {
		if (target < 0) {
			return;
		}
		if (target == 0) {
			result.push_back(v);
			return;
		}
		for (int n = candidates.size(), j = i; j < n; ++j) {
			if (j > i and candidates[j - 1] == candidates[j]) {
				continue;
			}
			v.push_back(candidates[j]);
			f(result, v, candidates, target - candidates[j], j + 1);
			v.pop_back();
		}
	}
};