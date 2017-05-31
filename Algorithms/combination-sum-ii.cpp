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

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		if (candidates.empty()) {
			return {};
		}
		sort(begin(candidates), end(candidates));
		vector<vector<int>> result;
		vector<int> v;
		dfs(result, candidates, v, target, 0, candidates.size());
		return result;
	}
private:
	void dfs(vector<vector<int>>& result, const vector<int>& candidates, vector<int>& v, int target, size_t i, const size_t n) {
		if (target == 0) {
			result.push_back(v);
			return;
		}
		if (target < 0) {
			return;
		}
		for (size_t j = i; j < n; j++) {
			if (j > i and candidates[j] == candidates[j - 1]) {
				continue;
			}
			int val = candidates[j];
			v.push_back(val);
			dfs(result, candidates, v, target - val, j + 1, n);
			v.pop_back();
		}
	}
};

int main(void) {
	Solution solution;
	int target;
	vector<int> candidates;
	vector<vector<int>> result, answer;

	target = 8;
	candidates = {10, 1, 2, 7, 6, 1, 5};
	answer = {{1, 7}, {1, 2, 5}, {2, 6}, {1, 1, 6}};
	sort(begin(answer), end(answer));
	result = solution.combinationSum2(candidates, target);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}