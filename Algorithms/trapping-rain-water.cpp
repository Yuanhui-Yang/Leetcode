// 42. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() < 3) {
			return 0;
		}
		int result = 0, n = height.size(), i = 0, j = n - 1, h1 = height[i], h2 = height[j];
		while (i + 1 < j) {
			if (h1 < h2) {
				i++;
				result += max(0, h1 - height[i]);
				h1 = max(h1, height[i]);
				continue;
			}
			j--;
			result += max(0, h2 - height[j]);
			h2 = max(h2, height[j]);
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> height;
	int result, answer;

	height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	answer = 6;
	result = solution.trap(height);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}