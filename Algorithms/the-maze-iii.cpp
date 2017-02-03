// 499. The Maze III
// https://leetcode.com/problems/the-maze-iii/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
		if (maze.empty() || maze.front().empty()) {
			return "impossible";
		}
		const int p = maze.size();
		const int q = maze.front().size();
		const vector<int> dx{-1, 0, 1, 0};
		const vector<int> dy{0, -1, 0, 1};
		const vector<char> directions{'u', 'l', 'd', 'r'};
		vector<vector<int>> distance(p, vector<int>(q, -1));
		vector<vector<string>> path(p, vector<string>(q));
		distance[ball[0]][ball[1]] = 0;
		list<vector<int>> queue;
		queue.push_back(ball);
		string result;
		while (!queue.empty()) {
			const vector<int> frontOfQueue = queue.front();
			queue.pop_front();
			const int currentX = frontOfQueue[0];
			const int currentY = frontOfQueue[1];
			const int currentD = distance[currentX][currentY];
			for (int i = 0; i < 4; i++) {
				int nextX = currentX;
				int nextY = currentY;
				int nextD = currentD;
				while (nextX + dx[i] >= 0 && nextX + dx[i] < p && nextY + dy[i] >= 0 && nextY + dy[i] < q && maze[nextX + dx[i]][nextY + dy[i]] == 0 && (nextX != hole[0] || nextY != hole[1])) {
					nextX += dx[i];
					nextY += dy[i];
					nextD++;
				}
				const vector<int> nextPoint{nextX, nextY};
				if (distance[nextX][nextY] < 0) {
					distance[nextX][nextY] = nextD;
					path[nextX][nextY] = path[currentX][currentY] + directions[i];
					if (nextPoint == hole) {
						result = path[nextX][nextY];
					}
					else {
						queue.push_back(nextPoint);
					}
					continue;
				}
				if (nextD < distance[nextX][nextY]) {
					distance[nextX][nextY] = nextD;
					path[nextX][nextY] = path[currentX][currentY] + directions[i];
					if (nextPoint == hole) {
						result = path[nextX][nextY];
					}
					else {
						queue.push_back(nextPoint);
					}
					continue;					
				}
				if (nextD == distance[nextX][nextY]) {
					if ((path[currentX][currentY] + directions[i]) < path[nextX][nextY]) {
						path[nextX][nextY] = path[currentX][currentY] + directions[i];
						if (nextPoint == hole) {
							result = path[nextX][nextY];
						}
						else {
							queue.push_back(nextPoint);
						}
					}
					continue;
				}
			}
		}
		return result.empty() ? "impossible" : result;
	}
};
int main(void) {
	Solution solution;
	vector<vector<int>> maze;
	vector<int> ball;
	vector<int> hole;
	string result;

	maze = {{0, 0, 0, 0, 0}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 0}};
	ball = {4, 3};
	hole = {0, 1};
	result = solution.findShortestWay(maze, ball, hole);
	assert("lul" == result);

	maze = {{0, 0, 0, 0, 0}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 0}};
	ball = {4, 3};
	hole = {3, 0};
	result = solution.findShortestWay(maze, ball, hole);
	assert("impossible" == result);

	cout << "\nPassed All\n";
	return 0;
}