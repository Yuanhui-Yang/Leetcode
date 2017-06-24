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
		int result = 0;
		stack<int> stk;
		heights.push_back(0);
		for (int n = heights.size(), i = 0; i < n; ++i) {
			while (!stk.empty() and heights[stk.top()] > heights[i]) {
				int j = stk.top(), h = heights[j];
				stk.pop();
				result = max(result, h * (i - (stk.empty() ? 0 : 1 + stk.top())));
			}
			stk.push(i);
		}
		heights.pop_back();
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