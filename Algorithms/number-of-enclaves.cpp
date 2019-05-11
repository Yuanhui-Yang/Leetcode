1020. Number of Enclaves
https://leetcode.com/problems/number-of-enclaves/

Given a 2D array A, each cell is 0 (representing sea) or 1 (representing land)

A move consists of walking from one land square 4-directionally to another land square, or off the boundary of the grid.

Return the number of land squares in the grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:

Input: [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: 
There are three 1s that are enclosed by 0s, and one 1 that isn't enclosed because its on the boundary.
Example 2:

Input: [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: 
All 1s are either on the boundary or can reach the boundary.
 

Note:

1 <= A.length <= 500
1 <= A[i].length <= 500
0 <= A[i][j] <= 1
All rows have the same size.

class Solution {
public:
	int numEnclaves(vector<vector<int>>& A) {
		int X = A.size(), Y = X ? A[0].size() : 0, result = 0;
		array<int, 4> dx = {0, -1, 0, 1}, dy = {-1, 0, 1, 0};
		for (int i = 0; i < X; ++i)
		{
			for (int j = 0; j < Y; ++j)
			{
				if (A[i][j] > 0)
				{
					queue<array<int, 2>> q;
					A[i][j] = -1;
					q.push({i, j});
					int cnt = 0, offboundary = 1;
					while (!q.empty())
					{
						++cnt;
						array<int, 2> from = q.front();
						q.pop();
						int x = from[0], y = from[1];
						for (int k = 0; k < 4; ++k)
						{
							int nx = x + dx[k], ny = y + dy[k];
							if (nx >= 0 and nx < X and ny >= 0 and ny < Y)
							{
								if (A[nx][ny] > 0)
								{
									A[nx][ny] = -1;
									q.push({nx, ny});
								}
							}
							else
							{
								offboundary = 0;
							}
						}
					}
					result += offboundary * cnt;
				}
			}
		}
		return result;
	}
};
