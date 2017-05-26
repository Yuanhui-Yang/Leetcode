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

#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
	bool operator< (const Point& other) const {
		return this->x == other.x ? this->y < other.y : this->x < other.x;
	}
	bool operator== (const Point& other) const {
		return this->x == other.x and this->y == other.y;
	}
};

class Solution {
public:
	vector<Point> outerTrees(vector<Point>& points) {
		if (points.empty()) {
			return {};
		}
		set<Point, Comp> rbtree(begin(points), end(points));
		vector<Point> result;
		Point end = *begin(rbtree), current = end, a(0, -1);
		while (1) {
			result.push_back(current);
			rbtree.erase(current);
			if (rbtree.empty()) {
				break;
			}
			rbtree.insert(end);
			Point next = *begin(rbtree);
			double c = -1;
			double d = INT_MAX;
			for (const auto &i : rbtree) {
				if (i.x == current.x and i.y == current.y) {
					continue;
				}
				Point b(i.x - current.x, i.y - current.y);
				double nc = cos(a, b);
				double nd = sqrt(b.x * b.x + b.y * b.y);
				if ((fabs(nc - c) < 1E-9 and nd < d) or (fabs(nc - c) > 1E-9 and nc > c)) {
					next = i;
					c = nc;
					d = nd;
				}
			}
			if (next.x == end.x and next.y == end.y) {
				break;
			}
			a.x = next.x - current.x;
			a.y = next.y - current.y;
			current = next;
		}
		return result;
	}
private:
	struct Comp {
		bool operator() (const Point& a, const Point& b) {
			return a.x == b.x ? a.y < b.y : a.x < b.x;
		}
	};
	double cos(const Point& a, const Point& b) {
		return double(a.x * b.x + a.y * b.y) / double (sqrt(a.x * a.x + a.y * a.y) * sqrt(b.x * b.x + b.y * b.y));
	}
};

int main(void) {
	Solution solution;
	vector<Point> points, result, answer;

	points = {{3, 0}, {4, 0}, {5, 0}, {6, 1}, {7, 2}, {7, 3}, {7, 4}, {6, 5}, {5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 4}, {1, 3}, {1, 2}, {2, 1}, {4, 2}, {0, 3}};
	answer = {{0, 3}, {1, 2}, {2, 1}, {3, 0}, {4, 0}, {5, 0}, {6, 1}, {7, 2}, {7, 3}, {7, 4}, {6, 5}, {5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 4}};
	sort(begin(answer), end(answer));
	result = solution.outerTrees(points);
	sort(begin(result), end(result));
	assert(answer == result);

	points = {{1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}};
	answer = {{1, 1}, {2, 0}, {4, 2}, {3, 3}, {2, 4}};
	sort(begin(answer), end(answer));
	result = solution.outerTrees(points);
	sort(begin(result), end(result));
	assert(answer == result);

	points = {{1, 2}, {2, 2}, {4, 2}};
	answer = {{1, 2}, {2, 2}, {4, 2}};
	sort(begin(answer), end(answer));
	result = solution.outerTrees(points);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
