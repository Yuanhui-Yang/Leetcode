// 39. Combination Sum
// https://leetcode.com/problems/combination-sum/

/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(begin(candidates), end(candidates));
		vector<vector<int>> result;
		vector<int> v;
		dfs(result, candidates, v, 0, target);
		return result;
	}
private:
	void dfs(vector<vector<int>>& result, vector<int>& candidates, vector<int>& v, int i, int target) {
		if (target == 0) {
			result.push_back(v);
			return;
		}
		int n = candidates.size();
		if (i >= n or target < 0) {
			return;
		}
		for (int j = i; j < n; ++j) {
			v.push_back(candidates[j]);
			dfs(result, candidates, v, j, target - candidates[j]);
			v.pop_back();
		}
	}
};

int main(void) {
	Solution solution;
	int target;
	vector<int> candidates;
	vector<vector<int>> result, answer;

	target = 7;
	candidates = {2, 3, 6, 7};
	answer = {{7}, {2, 2, 3}};
	sort(begin(answer), end(answer));
	result = solution.combinationSum(candidates, target);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}