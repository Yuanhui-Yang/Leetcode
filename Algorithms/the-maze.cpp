// 490. The Maze
// https://leetcode.com/problems/the-maze/
#include <iostream>
#include <cassert>
#include <vector>
#include <list>
#include <utility>
#include <set>
using namespace std;
class Solution {
public:
	bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		const int p = maze.size();
		if (!p) {
			return false;
		}
		const int q = maze.front().size();
		if (!q) {
			return false;
		}
		const vector<int> dx = {0, -1, 0, 1};
		const vector<int> dy = {-1, 0, 1, 0};
		list<vector<int>> queue;
		set<vector<int>> visited;
		queue.push_back(start);
		while (!queue.empty()) {
			const vector<int> frontOfQueue = queue.front();
			queue.pop_front();
			const int currentX = frontOfQueue[0];
			const int currentY = frontOfQueue[1];
			if (currentX == destination[0] && currentY == destination[1]) {
				return true;
			}
			for (int i = 0; i < 4; i++) {
				int nextX = currentX;
				int nextY = currentY;
				while (nextX + dx[i] >= 0 && nextX + dx[i] < p && nextY + dy[i] >= 0 && nextY + dy[i] < q && maze[nextX + dx[i]][nextY + dy[i]] == 0) {
					nextX += dx[i];
					nextY += dy[i];
				}
				const vector<int> next{nextX, nextY};
				if (!visited.count(next)) {
					queue.push_back(next);
					visited.insert(next);
				}
			}
		}
		return false;
	}
};
int main(void) {
	Solution solution;
	vector<vector<int>> maze;
	vector<int> start;
	vector<int> destination;
	bool result;

	maze = {{0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {1, 1, 0, 1, 1}, {0, 0, 0, 0, 0}};
	start = {0, 4};
	destination = {4, 4};
	result = solution.hasPath(maze, start, destination);
	assert(result);

	maze = {{0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {1, 1, 0, 1, 1}, {0, 0, 0, 0, 0}};
	start = {0, 4};
	destination = {3, 2};
	result = solution.hasPath(maze, start, destination);
	assert(!result);

	maze = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	start = {0, 0};
	destination = {1, 2};
	result = solution.hasPath(maze, start, destination);
	assert(!result);

	cout << "\nPassed All\n";
	return 0;
}