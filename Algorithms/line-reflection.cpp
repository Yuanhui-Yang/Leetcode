// 356. Line Reflection
// https://leetcode.com/problems/line-reflection/

/*
Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:
Given points = [[1,1],[-1,1]], return true.

Example 2:
Given points = [[1,1],[-1,-1]], return false.

Follow up:
Could you do better than O(n2)?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isReflected(vector<pair<int, int>>& points) {
		if (points.size() < 2) {
			return true;
		}
		sort(begin(points), end(points));
		int n = points.size(), i = 0, j = n - 1, k = points.front().first + points.back().first, l = 0;
		while (l < n and 2 * points[l].first < k) {
			++l;
		}
		sort(begin(points), next(begin(points), l), Comp());
		while (i <= j) {
			if (i > 0 and points[i] == points[i - 1]) {
				++i;
				continue;
			}
			if (j < n - 1 and points[j] == points[j + 1]) {
				--j;
				continue;
			}
			if (2 * points[i].first == k) {
				++i;
				continue;
			}
			if (2 * points[j].first == k) {
				--j;
				continue;
			}
			if (points[i].first + points[j].first == k and points[i].second == points[j].second) {
				++i;
				--j;
			}
			else {
				return false;
			}
		}
		return true;
	}
private:
	struct Comp {
		bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
			return a.first == b.first ? a.second > b.second : a.first < b.first;
		}
	};
};

int main(void) {
	Solution solution;
	vector<pair<int, int>> points;
	bool answer, result;

	points = {};
	answer = true;
	result = solution.isReflected(points);
	assert(answer == result);

	points = {{0, 0}};
	answer = true;
	result = solution.isReflected(points);
	assert(answer == result);

	points = {{0, 0}, {1, 0}, {3, 0}};
	answer = false;
	result = solution.isReflected(points);
	assert(answer == result);

	points = {{1, 2}, {2, 2}, {1, 4}, {2, 4}};
	answer = true;
	result = solution.isReflected(points);
	assert(answer == result);

	points = {{1, 1}, {-1, 1}};
	answer = true;
	result = solution.isReflected(points);
	assert(answer == result);

	points = {{1, 1}, {-1, -1}};
	answer = false;
	result = solution.isReflected(points);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}