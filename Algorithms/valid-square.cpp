// 593. Valid Square
// https://leetcode.com/problems/valid-square/

/*
Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
Note:

All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
*/

class Solution {
public:
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		array<vector<int>, 4> A;
		A[0] = p1;
		A[1] = p2;
		A[2] = p3;
		A[3] = p4;
		sort(begin(A), end(A));
		swap(A[2], A[3]);
		if (f(A[0], A[1], A[2])) {
			return false;
		}
		int len = g(A[1], A[0]);
		if (len == 0) {
			return false;
		}
		for (int i = 1; i < 4; ++i) {
			if (g(A[i], A[i - 1]) != len) {
				return false;
			}
		}
		return true;
	}
private:
	int f(vector<int> & p, vector<int> & q, vector<int> & r) {
		int result = 0;
		for (int sz = q.size(), i = 0; i < sz; ++i) {
			result += (p[i] - q[i]) * (r[i] - q[i]);
		}
		return result;
	}
	int g(vector<int> & p, vector<int> & q) {
		int a = p[0] - q[0], b = p[1] - q[1];
		return a * a + b * b;
	}
};