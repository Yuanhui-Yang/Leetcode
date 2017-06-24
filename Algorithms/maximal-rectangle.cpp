// 85. Maximal Rectangle
// https://leetcode.com/problems/maximal-rectangle/

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size(), n = m ? matrix.front().size() : 0;
		if (!m or !n) {
			return 0;
		}
		vector<int> v(n, 0);
		int result = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				v[j] = matrix[i][j] == '1' ? 1 + v[j] : 0;
			}
			result = max(result, f(v));
		}
		return result;
	}
private:
	int f(vector<int>& v) {
		v.push_back(0);
		int result = 0;
		stack<int> s;
		for (int n = v.size(), i = 0; i < n; ++i) {
			while(!s.empty() and v[s.top()] > v[i]) {
				int j = s.top(), h = v[j];
				s.pop();
				result = max(result, h * (i - (s.empty() ? 0 : 1 + s.top())));
			}
			s.push(i);
		}
		v.pop_back();
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<vector<char>> matrix;
	int answer, result;

	matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
	answer = 6;
	result = solution.maximalRectangle(matrix);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}