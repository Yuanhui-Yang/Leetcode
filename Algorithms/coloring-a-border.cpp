1034. Coloring A Border
https://leetcode.com/problems/coloring-a-border/

Given a 2-dimensional grid of integers, each value in the grid represents the color of the grid square at that location.

Two squares belong to the same connected component if and only if they have the same color and are next to each other in any of the 4 directions.

The border of a connected component is all the squares in the connected component that are either 4-directionally adjacent to a square not in the component, or on the boundary of the grid (the first or last row or column).

Given a square at location (r0, c0) in the grid and a color, color the border of the connected component of that square with the given color, and return the final grid.

 

Example 1:

Input: grid = [[1,1],[1,2]], r0 = 0, c0 = 0, color = 3
Output: [[3, 3], [3, 2]]
Example 2:

Input: grid = [[1,2,2],[2,3,2]], r0 = 0, c0 = 1, color = 3
Output: [[1, 3, 3], [2, 3, 3]]
Example 3:

Input: grid = [[1,1,1],[1,1,1],[1,1,1]], r0 = 1, c0 = 1, color = 2
Output: [[2, 2, 2], [2, 1, 2], [2, 2, 2]]
 

Note:

1 <= grid.length <= 50
1 <= grid[0].length <= 50
1 <= grid[i][j] <= 1000
0 <= r0 < grid.length
0 <= c0 < grid[0].length
1 <= color <= 1000

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int X = grid.size(), Y = X ? grid[0].size() : 0;
        if (!(0 <= r0 and r0 < X and c0 >= 0 and c0 < Y) or grid[r0][c0] == color)
        {
            return grid;
        }
        queue<array<int, 2>> q;
        q.push({r0, c0});
        int original_color = grid[r0][c0];
        grid[r0][c0] = -original_color;
        array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
        while (!q.empty())
        {
            array<int, 2> from = q.front();
            q.pop();
            int x = from[0], y = from[1];
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i], ny = y + dy[i];
                array<int, 2> to = {nx, ny};
                if (nx >= 0 and nx < X and ny >= 0 and ny < Y and grid[nx][ny] == original_color)
                {
                    grid[nx][ny] = -original_color;
                    q.push(to);
                }
            }
        }
        for (int x = 0; x < X; ++x)
        {
            for (int y = 0; y < Y; ++y)
            {
                if (grid[x][y] == -original_color)
                {
                    for (int i = 0; i < 4; ++i)
                    {
                        int nx = x + dx[i], ny = y + dy[i];
                        if (!(0 <= nx and nx < X and ny >= 0 and ny < Y) or (grid[nx][ny] > 0))
                        {
                            grid[x][y] = -color;
                        }
                    }   
                }
            }
        }
        for (auto & i : grid)
        {
            for (auto & j : i)
            {
                j = abs(j);
            }
        }
        return grid;
    }
};