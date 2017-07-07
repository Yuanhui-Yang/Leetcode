// 149. Max Points on a Line
// https://leetcode.com/problems/max-points-on-a-line/

/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
	int maxPoints(vector<Point>& points) {
		int n = points.size();
		if (n <= 2) {
			return n;
		}
		sort(begin(points), end(points), Comp());
		int result = 2;
		for (int i = 0; i + 1 < n; ++i) {
			unordered_map<long double, unordered_map<long double, int>> h;
			int cnt = 1;
			for (int j = i + 1; j < n; ++j) {
				int x1 = points[i].x, y1 = points[i].y;
				int x2 = points[j].x, y2 = points[j].y;
				if (x1 == x2 and y1 == y2) {
					result = max(result, ++cnt);
					continue;
				}
				array<long double, 2> line = f(x1, y1, x2, y2);
				result = max(result, ++h[line[0]][line[1]] + cnt);
			}
		}
		return result;
	}
private:
	array<long double, 2> f(long long x1, long long y1, long long x2, long long y2) {
		array<long double, 2> result;
		if (x1 == x2) {
			result[0] = x1;
			result[1] = numeric_limits<long double>::max();
		}
		else {
			result[0] = (long double)(x1 * y2 - x2 * y1) / (long double)(x1 - x2);
			result[1] = (long double)(y1 - y2) / (long double)(x1 - x2);
		}
		return result;
	}
	struct Comp {
		bool operator() (const Point & a, const Point &b) {
			if (a.x == b.x) {
				return a.y < b.y;
			}
			return a.x < b.x;
		}
	};
};