// 447. Number of Boomerangs
// https://leetcode.com/problems/number-of-boomerangs/

/*
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
*/

class Solution {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int sz = points.size(), result = 0;
		for (int i = 0; i < sz; ++i) {
			unordered_map<int, int> A;
			for (int j = 0; j < sz; ++j) {
				if (i == j) {
					continue;
				}
				++A[f(points[i], points[j])];
			}
			for (const auto & i : A) {
				result += i.second * (i.second  - 1);
			}
		}
		return result;
	}
private:
	int f(const pair<int, int> & a,  const pair<int, int> & b) {
		return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
	}
};