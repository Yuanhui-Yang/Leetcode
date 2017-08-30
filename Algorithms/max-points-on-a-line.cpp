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
		int sz = points.size(), result = 0;
		for (int i = 0; i < sz; ++i) {
			map<array<int, 2>, int> A;
			int B = 1, C = 0;
			for (int j = 0; j < sz; ++j) {
				if (i != j) {
					int x = points[j].x - points[i].x, y = points[j].y - points[i].y;
					if (x == 0 and y == 0) {
						++B;
					}
					else {
						C = max(C, ++A[f1(x, y)]);
					}
				}
			}
			result = max(result, B + C);
		}
		return result;
	}
private:
	array<int, 2> f1(int x, int y) {
		int z = f2(x, y);
		return {x / z, y / z};
	}
	int f2(int x, int y) {
		return y == 0 ? x : f2(y, x % y);
	}
};