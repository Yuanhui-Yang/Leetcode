// 84. Largest Rectangle in Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/

/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		stack<int> s;
		heights.push_back(0);
		int result = 0;
		for (int n = heights.size(), i = 0; i < n; ++i) {
			while (!s.empty() and heights[s.top()] >= heights[i]) {
				int j = s.top();
				s.pop();
				result = max(result, heights[j] * (i - (s.empty() ? 0 : s.top() + 1)));
			}
			s.push(i);
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> heights;
	int anwer, result;

	heights = {3, 6, 5, 7, 4, 8, 1, 0};
	anwer = 20;
	result = solution.largestRectangleArea(heights);
	assert(anwer == result);

	heights = {1, 2, 2};
	anwer = 4;
	result = solution.largestRectangleArea(heights);
	assert(anwer == result);

	heights = {1};
	anwer = 1;
	result = solution.largestRectangleArea(heights);
	assert(anwer == result);

	heights = {4, 2, 0, 3, 2, 5};
	anwer = 6;
	result = solution.largestRectangleArea(heights);
	assert(anwer == result);

	heights = {2, 1, 5, 6, 2, 3};
	anwer = 10;
	result = solution.largestRectangleArea(heights);
	assert(anwer == result);

	cout << "\nPassed All\n";
	return 0;
}