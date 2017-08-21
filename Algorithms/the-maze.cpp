// 490. The Maze
// https://leetcode.com/problems/the-maze/

/*
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

Example 1

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

Example 2

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: false
Explanation: There is no way for the ball to stop at the destination.

Note:
There is only one ball and one destination in the maze.
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
*/

class Solution {
public:
	bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		int P = maze.size(), Q = P == 0 ? 0 : maze[0].size();
		array<int, 4> dx({0, -1, 0, 1}), dy({-1, 0, 1, 0});
		stack<array<int, 2>> curr;
		curr.push({start[0], start[1]});
		maze[start[0]][start[1]] = -1;
		array<int, 2> dest({destination[0], destination[1]});
		while (!curr.empty()) {
			array<int, 2> top = curr.top();
			curr.pop();
			if (top == dest) {
				return true;
			}
			int x = top[0], y = top[1];
			for (int i = 0; i < 4; ++i) {
				int nx = x, ny = y;
				while (nx + dx[i] >= 0 and nx + dx[i] < P and ny + dy[i] >= 0 and ny + dy[i] < Q and maze[nx + dx[i]][ny + dy[i]] <= 0) {
					nx += dx[i];
					ny += dy[i];
				}
				if ((nx != x or ny != y) and (maze[nx][ny] == 0)) {
					maze[nx][ny] = -1;
					curr.push({nx, ny});
				}
			}
		}
		return false;
	}
};