// 499. The Maze III
// https://leetcode.com/problems/the-maze-iii/

/*
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up (u), down (d), left (l) or right (r), but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction. There is also a hole in this maze. The ball will drop into the hole if it rolls on to the hole.

Given the ball position, the hole position and the maze, find out how the ball could drop into the hole by moving the shortest distance. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the hole (included). Output the moving directions by using 'u', 'd', 'l' and 'r'. Since there could be several different shortest ways, you should output the lexicographically smallest way. If the ball cannot reach the hole, output "impossible".

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The ball and the hole coordinates are represented by row and column indexes.

Example 1

Input 1: a maze represented by a 2D array

0 0 0 0 0
1 1 0 0 1
0 0 0 0 0
0 1 0 0 1
0 1 0 0 0

Input 2: ball coordinate (rowBall, colBall) = (4, 3)
Input 3: hole coordinate (rowHole, colHole) = (0, 1)

Output: "lul"
Explanation: There are two shortest ways for the ball to drop into the hole.
The first way is left -> up -> left, represented by "lul".
The second way is up -> left, represented by 'ul'.
Both ways have shortest distance 6, but the first way is lexicographically smaller because 'l' < 'u'. So the output is "lul".

Example 2

Input 1: a maze represented by a 2D array

0 0 0 0 0
1 1 0 0 1
0 0 0 0 0
0 1 0 0 1
0 1 0 0 0

Input 2: ball coordinate (rowBall, colBall) = (4, 3)
Input 3: hole coordinate (rowHole, colHole) = (3, 0)
Output: "impossible"
Explanation: The ball cannot reach the hole.

Note:
There is only one ball and one hole in the maze.
Both the ball and hole exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and the width and the height of the maze won't exceed 30.
*/

class Solution {
public:
	string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
		int P = maze.size(), Q = P == 0 ? 0 : maze[0].size();
		if (P == 0 or Q == 0) {
			return "impossible";
		}
		if (ball == hole) {
			return "";
		}
		string result("impossible");
		vector<vector<int>> A(P, vector<int>(Q, INT_MAX));
		vector<vector<string>> B(P, vector<string>(Q, ""));
		array<int, 4> dx({0, -1, 0, 1}), dy({-1, 0, 1, 0});
		array<char, 4> dpath({'l', 'u', 'r', 'd'});
		queue<array<int, 2>> curr;
		curr.push({ball[0], ball[1]});
		A[ball[0]][ball[1]] = 0;
		while (!curr.empty()) {
			array<int, 2> front = curr.front();
			curr.pop();
			int x = front[0], y = front[1], z = A[x][y];
			string path(B[x][y]);
			for (int i = 0; i < 4; ++i) {
				int nx = x, ny = y, nz = z;
				string npath(path);
				while (nx + dx[i] >= 0 and nx + dx[i] < P and ny + dy[i] >= 0 and ny + dy[i] < Q and maze[nx + dx[i]][ny + dy[i]] == 0 and !(nx == hole[0] and ny == hole[1])) {
					nx += dx[i];
					ny += dy[i];
					++nz;
				}
				if (z < nz) {
					npath.push_back(dpath[i]);
					if (nz < A[nx][ny]) {
						A[nx][ny] = nz;
						B[nx][ny] = npath;
						if (nx == hole[0] and ny == hole[1]) {
							result = npath;
						}
						else {
							curr.push({nx, ny});
						}
					}
					else if (nz == A[nx][ny] and npath < B[nx][ny]) {
						B[nx][ny] = npath;
						if (nx == hole[0] and ny == hole[1]) {
							result = npath;
						}
						else {
							curr.push({nx, ny});
						}
					}
				}
			}
		}
		return result;
	}
};