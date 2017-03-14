// 391. Perfect Rectangle
// https://leetcode.com/problems/perfect-rectangle/

// Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.

// Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).


// Example 1:

// rectangles = [
//   [1,1,3,3],
//   [3,1,4,2],
//   [3,2,4,4],
//   [1,3,2,4],
//   [2,3,3,4]
// ]

// Return true. All 5 rectangles together form an exact cover of a rectangular region.

// Example 2:

// rectangles = [
//   [1,1,2,3],
//   [1,3,2,4],
//   [3,1,4,2],
//   [3,2,4,4]
// ]

// Return false. Because there is a gap between the two rectangular regions.

// Example 3:

// rectangles = [
//   [1,1,3,3],
//   [3,1,4,2],
//   [1,3,2,4],
//   [3,2,4,4]
// ]

// Return false. Because there is a gap in the top center.

// Example 4:

// rectangles = [
//   [1,1,3,3],
//   [3,1,4,2],
//   [1,3,2,4],
//   [2,2,4,4]
// ]

// Return false. Because two of the rectangles overlap with each other.

#include <iostream> // std::cout; std::cin
#include <cstdlib> // rand
#include <cassert> // assert
#include <cctype> // isalnum; isalpha; isdigit; islower; isupper; isspace; tolower; toupper
#include <cmath> // pow; sqrt; round; fabs; abs; log
#include <climits> // INT_MIN; INT_MAX; LLONG_MIN; LLONG_MAX; ULLONG_MAX
#include <cfloat> // DBL_EPSILON; LDBL_EPSILON
#include <cstring> // memset
#include <algorithm> // max; min; min_element; max_element; minmax_element; next_permutation; prev_permutation; nth_element; sort; swap; lower_bound; upper_bound; reverse
#include <limits> // std::numeric_limits<int>::min; std::numeric_limits<int>::max; std::numeric_limits<double>::epsilon; std::numeric_limits<long double>::epsilon;
#include <numeric> // std::accumulate; std::iota
#include <string> // std::string::npos
#include <list>
#include <bitset>
#include <vector>
#include <deque>
#include <stack> // std::stack::top; std::stack::pop; std::stack::push
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility> // pair; make_pair; swap
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

class Solution {
public:
	bool isRectangleCover(vector<vector<int>>& rectangles) {
		if (rectangles.empty()) {
			return false;
		}
		int left = INT_MAX, right = INT_MIN, bottom = INT_MAX, top = INT_MIN;
		for (const auto &i : rectangles) {
			if (i.at(0) < i.at(2) and i.at(1) < i.at(3)) {
				left = min(left, i.at(0));
				right = max(right, i.at(2));
				bottom = min(bottom, i.at(1));
				top = max(top, i.at(3));
				continue;
			}
			return false;
		}
		for (auto &i : rectangles) {
			i.at(0) -= left;
			i.at(2) -= left;
			i.at(1) -= bottom;
			i.at(3) -= bottom;
		}
		right -= left;
		left = 0;
		top -= bottom;
		bottom = 0;
		vector<Line> v;
		for (const auto &i : rectangles) {
			if (i.at(1) == 0) {
				v.push_back(Line(i.at(0), i.at(3), false));
				v.push_back(Line(i.at(2), i.at(3), true));
				continue;
			}
			v.push_back(Line(i.at(0), i.at(1), true));
			v.push_back(Line(i.at(0), i.at(3), false));
			v.push_back(Line(i.at(2), i.at(3), true));
			v.push_back(Line(i.at(2), i.at(1), false));
		}
		sort(begin(v), end(v), Comp1());
		set<Line, Comp2> rbtree;
		for (int i = 0, n = v.size(); i < n; i++) {
			const Line &line = v.at(i);
			if (i == 0 or !line.d) {
				rbtree.insert(line);
				continue;
			}
			if (rbtree.empty()) {
				return false;
			}
			const Line target(line.x, line.y, false);
			const set<Line, Comp2>::iterator it = rbtree.lower_bound(target);
			if (it == end(rbtree) or it->y != line.y) {
				return false;
			}
			rbtree.erase(it);
			if (rbtree.empty() and i + 1 < n) {
				return false;
			}
			if (prev(end(rbtree))->y < top) {
				return false;
			}
		}
		return rbtree.empty();
	}
private:
	struct Line {
		Line(int x, int y, bool d) {
			this->x = x;
			this->y = y;
			this->d = d;
		}
		int x;
		int y;
		bool d;
	};
private:
	struct Comp1 {
		bool operator() (const Line& a, const Line& b) {
			if (a.x == b.x) {
				if (a.d == b.d) {
					return a.y < b.y;
				}
				return a.d < b.d;
			}
			return a.x < b.x;
		}
	};
private:
	struct Comp2 {
		bool operator() (const Line& a, const Line& b) {
			if (a.y == b.y) {
				if (a.x == b.x) {
					return a.d < b.d;
				}
				return a.x > b.x;
			}
			return a.y < b.y;
		}
	};
};

int main(void) {
	Solution solution;
	vector<vector<int>> rectangles;
	bool result, answer;

	rectangles = {{1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4}};
	answer = true;
	result = solution.isRectangleCover(rectangles);
	assert(answer == result);

	rectangles = {{1, 1, 2, 3}, {1, 3, 2, 4}, {3, 1, 4, 2}, {3, 2, 4, 4}};
	answer = false;
	result = solution.isRectangleCover(rectangles);
	assert(answer == result);

	rectangles = {{1, 1, 3, 3}, {3, 1, 4, 2}, {1, 3, 2, 4}, {3, 2, 4, 4}};
	answer = false;
	result = solution.isRectangleCover(rectangles);
	assert(answer == result);

	rectangles = {{1, 1, 3, 3}, {3, 1, 4, 2}, {1, 3, 2, 4}, {2, 2, 4, 4}};
	answer = false;
	result = solution.isRectangleCover(rectangles);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}