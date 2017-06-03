// 22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		string s;
		dfs(result, s, 0, 0, n);
		return result;
	}
private:
	void dfs(vector<string>& result, string& s, int l,  int r, int n) {
		if (l == n and r == n) {
			result.push_back(s);
			return;
		}
		if (l < n) {
			s.push_back('(');
			dfs(result, s, l + 1, r, n);
			s.pop_back();
		}
		if (r < l) {
			s.push_back(')');
			dfs(result, s, l, r + 1, n);
			s.pop_back();
		}
	}
};

int main(void) {
	Solution solution;
	int n;
	vector<string> answer, result;

	n = 3;
	answer = {"((()))", "(()())", "(())()", "()(())", "()()()"};
	sort(begin(answer), end(answer));
	result = solution.generateParenthesis(n);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}