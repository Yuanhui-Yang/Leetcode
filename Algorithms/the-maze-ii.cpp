// 505. The Maze II
// https://leetcode.com/problems/the-maze-ii/

/*
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.

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

Output: 12
Explanation: One shortest way is : left -> down -> left -> down -> right -> down -> right.
			 The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.

Example 2

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: -1
Explanation: There is no way for the ball to stop at the destination.

Note:
There is only one ball and one destination in the maze.
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
*/

class Solution {
public:
	int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		int P = maze.size(), Q = P == 0 ? 0 : maze[0].size();
		if (P == 0 or Q == 0) {
			return -1;
		}
		array<int, 4> dx({0, -1, 0, 1}), dy({-1, 0, 1, 0});
		vector<vector<bool>> A(P, vector<bool>(Q, true));
		priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
		pq.push({0, start[0], start[1]});
		while (!pq.empty()) {
			array<int, 3> top = pq.top();
			pq.pop();
			int x = top[1], y = top[2], z = top[0];
			if (x == destination[0] and y == destination[1]) {
				return z;
			}
			if (A[x][y]) {
				A[x][y] = false;
				for (int i = 0; i < 4; ++i) {
					int nx = x, ny = y, nz = z;
					while (nx + dx[i] >= 0 and nx + dx[i] < P and ny + dy[i] >= 0 and ny + dy[i] < Q and maze[nx + dx[i]][ny + dy[i]] == 0) {
						nx += dx[i];
						ny += dy[i];
						++nz;
					}
					if (nz != z and A[nx][ny]) {
						pq.push({nz, nx, ny});
					}
				}
			}
		}
		return -1;
	}
};