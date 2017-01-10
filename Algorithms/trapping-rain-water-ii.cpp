// 407. Trapping Rain Water II
// https://leetcode.com/problems/trapping-rain-water-ii/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
using namespace std;
class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		if (heightMap.size() < 3 || heightMap.front().size() < 3) return 0;
		const int x_size = heightMap.size(), y_size = heightMap.front().size();
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> min_heap;
		for (int i = 1; i + 1 < x_size; i++) {
			min_heap.push({heightMap[i][0], {i, 0}});
			min_heap.push({heightMap[i][y_size - 1], {i, y_size - 1}});
		}
		for (int j = 1; j + 1 < y_size; j++) {
			min_heap.push({heightMap[0][j], {0, j}});
			min_heap.push({heightMap[x_size - 1][j], {x_size - 1, j}});
		}
		vector<vector<bool>> visited(x_size, vector<bool>(heightMap.front().size(), false));
		for (int i = 0; i < x_size; i++) {
			visited[i][0] = true;
			visited[i][y_size - 1] = true;
		}
		for (int j = 0; j < y_size; j++) {
			visited[0][j] = true;
			visited[x_size - 1][j] = true;
		}
		int result = 0;
		const vector<int> dx = {-1, 0, 1, 0};
		const vector<int> dy = {0, -1, 0, 1};
		while (!min_heap.empty()) {
			pair<int, pair<int, int>> min_heap_top = min_heap.top();
			min_heap.pop();
			const int x = min_heap_top.second.first;
			const int y = min_heap_top.second.second;
			for (int i = 0; i < 4; i++) {
				const int x_next = x + dx[i];
				const int y_next = y + dy[i];
				if (x_next >= 0 && x_next < x_size && y_next >= 0 && y_next < y_size && !visited[x_next][y_next]) {
					visited[x_next][y_next] = true;
					if (min_heap_top.first >= heightMap[x_next][y_next]) {
						result += min_heap_top.first - heightMap[x_next][y_next];
						min_heap.push({min_heap_top.first, {x_next, y_next}});
						continue;
					}
					min_heap.push({heightMap[x_next][y_next], {x_next, y_next}});
					continue;
				}
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<vector<int>> heightMap;
	int result = 0;
	heightMap = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
	result = solution.trapRainWater(heightMap);
	assert(4 == result);
	cout << "\nPassed All\n";
	return 0;
}