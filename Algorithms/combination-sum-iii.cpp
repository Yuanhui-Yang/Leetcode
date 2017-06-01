// 216. Combination Sum III
// https://leetcode.com/problems/combination-sum-iii/

/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> result;
		vector<int> v;
		dfs(result, v, 1, k, n);
		return result;
	}
private:
	void dfs(vector<vector<int>>& result, vector<int>& v, int i, int k, int n) {
		if (n == 0 and k == 0) {
			result.push_back(v);
			return;
		}
		for (int j = i; n > 0 and j <= 9; j++) {
			v.push_back(j);
			dfs(result, v, j + 1, k - 1, n - j);
			v.pop_back();
		}
	}
};

int main(void) {
	Solution solution;
	int k, n;
	vector<vector<int>> answer, result;

	k = 3;
	n = 7;
	answer = {{1, 2, 4}};
	sort(begin(answer), end(answer));
	result = solution.combinationSum3(k, n);
	sort(begin(result), end(result));
	assert(answer == result);

	k = 3;
	n = 9;
	answer = {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}};
	sort(begin(answer), end(answer));
	result = solution.combinationSum3(k, n);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}