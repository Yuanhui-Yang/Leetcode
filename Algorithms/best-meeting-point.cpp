// 296. Best Meeting Point
// https://leetcode.com/problems/best-meeting-point/

/*
A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.
*/

class Solution {
public:
	int minTotalDistance(vector<vector<int>>& grid) {
		int M = grid.size(), N = M == 0 ? 0 : grid[0].size();
		vector<int> X, Y;
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				if (grid[i][j] == 1) {
					X.push_back(i);
					Y.push_back(j);
				}
			}
		}
		int result = 0;
		nth_element(begin(X), next(begin(X), X.size() / 2), end(X));
		nth_element(begin(Y), next(begin(Y), Y.size() / 2), end(Y));
		int a = *next(begin(X), X.size() / 2), b = *next(begin(Y), Y.size() / 2);
		for (const auto & i : X) {
			result += abs(i - a);
		}
		for (const auto & i : Y) {
			result += abs(i - b);
		}
		return result;
	}
};