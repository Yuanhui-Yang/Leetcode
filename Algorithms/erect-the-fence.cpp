// 587. Erect the Fence
// https://leetcode.com/problems/erect-the-fence/

/*
There are some trees, where each tree is represented by (x,y) coordinate in a two-dimensional garden. Your job is to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed. Your task is to help find the coordinates of trees which are exactly located on the fence perimeter.

Example 1:
Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
Explanation:

Example 2:
Input: [[1,2],[2,2],[4,2]]
Output: [[1,2],[2,2],[4,2]]
Explanation:

Even you only have trees in a line, you need to use rope to enclose them. 
Note:

All trees should be enclosed together. You cannot cut the rope to enclose trees that will separate them in more than one group.
All input integers will range from 0 to 100.
The garden has at least one tree.
All coordinates are distinct.
Input points have NO order. No order required for output.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct Point {
	int x, y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

Point origin;

int f1(const Point & p, const Point & q, const Point & r) {
	int x1 = q.x - p.x, y1 = q.y - p.y, x2 = r.x - q.x, y2 = r.y - q.y;
	return x1 * y2 - y1 * x2;
}

 int f2(const Point & a, const Point & b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

struct Comp {
	bool operator() (const Point & a, const Point & b) {
		int c = f1(origin, a, b), d1 = f2(origin, a), d2 = f2(origin, b);
		if (c == 0) {
			return d1 < d2;
		}
		return c > 0;
	}
};

class Solution {
public:
	vector<Point> outerTrees(vector<Point>& points) {
		int sz = points.size(), i = 0, originId = 0;
		for (i = 0; i < sz; ++i) {
			if (points[i].x < points[originId].x) {
				originId = i;
			}
			else if (points[i].x == points[originId].x and points[i].y < points[originId].y) {
				originId = i;
			}
		}
		origin = points[originId];
		vector<Point> result;
		sort(begin(points), end(points), Comp());
		i = sz - 1;
		while (i - 1 >= 0 and f1(origin, points[i - 1], points[i]) == 0) {
			--i;
		}
		reverse(next(begin(points), i), end(points));
		for (i = 0; i < sz; ++i) {
			while (result.size() >= 2 and f1(result[result.size() - 2], result[result.size() - 1], points[i % sz]) < 0) {
				result.pop_back();
			}
			result.push_back(points[i]);
		}
		return result;
	}

};

int main(void) {
	Solution solution;
	vector<Point> points, result;
	
	points = {{1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}};
	result = solution.outerTrees(points);
	for (const auto & i : result) {
		cout << '(' << i.x << ',' << i.y << ')' << '\t';
	}
	cout << '\n';
	
	points = {{1, 2}, {2, 2}, {4, 2}};
	result = solution.outerTrees(points);
	for (const auto & i : result) {
		cout << '(' << i.x << ',' << i.y << ')' << '\t';
	}
	cout << '\n';

	points = {{3, 0}, {4, 0}, {5, 0}, {6, 1}, {7, 2}, {7, 3}, {7, 4}, {6, 5}, {5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 4}, {1, 3}, {1, 2}, {2, 1}, {4, 2}, {0, 3}};
	result = solution.outerTrees(points);
	for (const auto & i : result) {
		cout << '(' << i.x << ',' << i.y << ')' << '\t';
	}
	cout << '\n';
	
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct Point {
	int x, y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

struct Comp {
	bool operator() (const Point & a, const Point & b) {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		return a.x < b.x;
	}
};

class Solution {
public:
	vector<Point> outerTrees(vector<Point>& points) {
		int sz = points.size(), i = 0;
		if (sz <= 3) {
			return points;
		}
		sort(begin(points), end(points), Comp());
		vector<Point> result;
		for (i = 0; i < sz; ++i) {
			while (result.size() >= 2 and f(result[result.size() - 2], result[result.size() - 1], points[i]) < 0) {
				result.pop_back();
			}
			result.push_back(points[i]);
		}
		for (i = sz - 2; i >= 0; --i) {
			while (result.size() >= 2 and f(result[result.size() - 2], result[result.size() - 1], points[i]) < 0) {
				result.pop_back();
			}
			result.push_back(points[i]);
		}
		result.pop_back();
		return result;
	}
private:
	int f(const Point & p, const Point & q, const Point & r) {
		int x1 = q.x - p.x, y1 = q.y - p.y, x2 = r.x - q.x, y2 = r.y - q.y;
		return x1 * y2 - y1 * x2;
	}
};

int main(void) {
	Solution solution;
	vector<Point> points, result;
	
	points = {{1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}};
	result = solution.outerTrees(points);
	for (const auto & i : result) {
		cout << '(' << i.x << ',' << i.y << ')' << '\t';
	}
	cout << '\n';
	
	points = {{1, 2}, {2, 2}, {4, 2}};
	result = solution.outerTrees(points);
	for (const auto & i : result) {
		cout << '(' << i.x << ',' << i.y << ')' << '\t';
	}
	cout << '\n';

	points = {{3, 0}, {4, 0}, {5, 0}, {6, 1}, {7, 2}, {7, 3}, {7, 4}, {6, 5}, {5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 4}, {1, 3}, {1, 2}, {2, 1}, {4, 2}, {0, 3}};
	result = solution.outerTrees(points);
	for (const auto & i : result) {
		cout << '(' << i.x << ',' << i.y << ')' << '\t';
	}
	cout << '\n';
	
	return 0;
}