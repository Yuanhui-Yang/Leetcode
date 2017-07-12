// 223. Rectangle Area
// https://leetcode.com/problems/rectangle-area/

/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.
*/

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		vector<Line> V;
		V.push_back(Line(A, B, D, -1));
		V.push_back(Line(C, B, D, 1));
		V.push_back(Line(E, F, H, -1));
		V.push_back(Line(G, F, H, 1));
		sort(begin(V), end(V));
		int result = 0;
		multiset<array<int, 2>> W;
		for (int sz = V.size(), i = 0; i + 1 < sz; ++i) {
			array<int, 2> e({V[i].y1, V[i].y2});
			if (V[i].z < 0) {
				W.insert(e);
			}
			else {
				W.erase(W.find(e));
			}
			int dx = V[i + 1].x - V[i].x, dy = f(W);
			result += dx * dy;
		}
		return result;
	}
private:
	struct Line {
		int x, y1, y2, z;
		Line(int x, int y1, int y2, int z) {
			this->x = x;
			this->y1 = y1;
			this->y2 = y2;
			this->z = z;
		}
		bool operator< (const Line & other) {
			if (this->x == other.x) {
				if (this->z == other.z) {
					if (this->z < 0) {
						return this->y1 < other.y1;
					}
					return this->y1 > other.y1;
				}
				return this->z < other.z;
			}
			return this->x < other.x;
		} 
	};
	int f(const multiset<array<int, 2>> & W) {
		if (W.empty()) {
			return 0;
		}
		int result = 0;
		for (multiset<array<int, 2>>::iterator it = begin(W), jt = end(W); it != jt; ++it) {
			int a = (*it)[0], b = (*it)[1];
			while (next(it) != jt and (*next(it))[0] <= b) {
				b = max(b, (*next(it))[1]);
				++it;
			}
			result += b - a;
		}
		return result;
	}
};