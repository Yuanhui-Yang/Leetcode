// 407. Trapping Rain Water II
// https://leetcode.com/problems/trapping-rain-water-ii/

/*
Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

Note:
Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.

Example:

Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.

The above image represents the elevation map [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.


After the rain, water are trapped between the blocks. The total volume of water trapped is 4.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		if (heightMap.size() < 3 or heightMap.front().size() < 3) {
			return 0;
		}
		const int m = heightMap.size(), n = heightMap.front().size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		for (int i = 0; i < m; i++) {
			pair<int, pair<int, int>> a = {heightMap[i].front(), {i, 0}}, b = {heightMap[i].back(), {i, n - 1}};
			visited[i].front() = true;
			visited[i].back() = true;
			pq.push(a);
			pq.push(b);
		}
		for (int j = 0; j < n; j++) {
			pair<int, pair<int, int>> a = {heightMap.front()[j], {0, j}}, b = {heightMap.back()[j], {m - 1, j}};
			visited.front()[j] = true;
			visited.back()[j] = true;
			pq.push(a);
			pq.push(b);
		}
		int result = 0;
		const int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
		while (!pq.empty()) {
			pair<int, pair<int, int>> t = pq.top();
			pq.pop();
			int x = t.second.first, y = t.second.second, z = t.first;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 and nx < m and ny >= 0 and ny < n and !visited[nx][ny]) {
					int nz = heightMap[nx][ny];
					pair<int, pair<int, int>> c = {max(nz, z), {nx, ny}};
					visited[nx][ny] = true;
					result += max(0, z - nz);
					pq.push(c);
				}
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;

	vector<vector<int>> heightMap;
	int result, answer;

	heightMap = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
	answer = 4;
	result = solution.trapRainWater(heightMap);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}