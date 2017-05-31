// 77. Combinations
// https://leetcode.com/problems/combinations/

/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

{
  {2,4},
  {3,4},
  {2,3},
  {1,2},
  {1,3},
  {1,4},
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> v(n), w;
		iota(begin(v), end(v), 1);
		vector<vector<int>> result;
		dfs(result, v, w, 0, n, k);
		return result;
	}
private:
	void dfs(vector<vector<int>>& result, const vector<int>& v, vector<int>& w, int i, const size_t n, const size_t k) {
		if (w.size() == k) {
			result.push_back(w);
			return;
		}
		for (size_t j = i; j < n; j++) {
			w.push_back(v[j]);
			dfs(result, v, w, j + 1, n, k);
			w.pop_back();
		}
	}
};

int main(void) {
	Solution solution;
	int n, k;
	vector<vector<int>> result, answer;

	n = 4;
	k = 2;
	answer = {{2, 4}, {3, 4}, {2, 3}, {1, 2}, {1, 3}, {1, 4}};
	sort(begin(answer), end(answer));
	result = solution.combine(n, k);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
