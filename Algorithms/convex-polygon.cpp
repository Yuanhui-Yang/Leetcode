// 469. Convex Polygon
// https://leetcode.com/problems/convex-polygon/

/*
Given a list of points that form a polygon when joined sequentially, find if this polygon is convex (Convex polygon definition).

Note:

There are at least 3 and at most 10,000 points.
Coordinates are in the range -10,000 to 10,000.
You may assume the polygon formed by given points is always a simple polygon (Simple polygon definition). In other words, we ensure that exactly two edges intersect at each vertex, and that edges otherwise don't intersect each other.
Example 1:

[[0,0],[0,1],[1,1],[1,0]]

Answer: True

Explanation:
Example 2:

[[0,0],[0,10],[10,10],[10,0],[5,5]]

Answer: False

Explanation:
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isConvex(vector<vector<int>>& points) {
		int sz = points.size(), i = 0, init = 0, curr = 0;
		if (sz < 3) {
			return false;
		}
		for (i = 0; i < sz; ++i) {
			curr = f(points[i % sz], points[(i + 1) % sz], points[(i + 2) % sz]);
			if (curr) {
				if (init == 0) {
					init = curr;
				}
				else if ((init < 0 and curr > 0) or (init > 0 and curr < 0)) {
					return false;
				}
			}
		}
		return init;
	}
private:
	int f(const vector<int> & a, const vector<int> & b, const vector<int> & c) {
		int x1 = b[0] - a[0], y1 = b[1] - a[1], x2 = c[0] - b[0], y2 = c[1] - b[1];
		return x1 * y2 - y1 * x2;
	}
};

int main(void) {
	Solution solution;
	vector<vector<int>> points;

	points = {{0, 0}, {0, 1}, {1, 1}, {1, 0}};
	cout << boolalpha << solution.isConvex(points) << '\n';

	points = {{0, 0}, {0, 10}, {10, 10}, {10, 0}, {5, 5}};
	cout << boolalpha << solution.isConvex(points) << '\n';

	points = {{0, 0}, {1, 1}, {0, 2}, {-1, 2}, {0, 1}};
	cout << boolalpha << solution.isConvex(points) << '\n';

	return 0;
}