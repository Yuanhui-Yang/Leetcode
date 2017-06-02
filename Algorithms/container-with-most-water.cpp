// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/

/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int result = 0, n = height.size(), i = 0, j = n - 1, h1 = height[i], h2 = height[j];
		while (i < j) {
			result = max(result, (j - i) * min(h1, h2));
			if (h1 < h2) {
				h1 = max(h1, height[++i]);
			}
			else {
				h2 = max(h2, height[--j]);
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> height;
	int answer, result;

	height = {1, 2, 4, 3};
	answer = 4;
	result = solution.maxArea(height);
	assert(answer == result);

	height = {1, 1};
	answer = 1;
	result = solution.maxArea(height);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}