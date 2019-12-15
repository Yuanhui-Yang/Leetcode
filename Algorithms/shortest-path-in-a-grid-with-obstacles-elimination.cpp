/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 *
 * https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/
 *
 * algorithms
 * Hard (31.67%)
 * Likes:    44
 * Dislikes: 0
 * Total Accepted:    1.4K
 * Total Submissions: 4.4K
 * Testcase Example:  '[[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]]\n1'
 *
 * Given a m * n grid, where each cell is either 0 (empty) or 1 (obstacle). In
 * one step, you can move up, down, left or right from and to an empty cell.
 * 
 * Return the minimum number of steps to walk from the upper left corner (0, 0)
 * to the lower right corner (m-1, n-1) given that you can eliminate at most k
 * obstacles. If it is not possible to find such walk return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * grid = 
 * [[0,0,0],
 * [1,1,0],
 * ⁠[0,0,0],
 * [0,1,1],
 * ⁠[0,0,0]], 
 * k = 1
 * Output: 6
 * Explanation: 
 * The shortest path without eliminating any obstacle is 10. 
 * The shortest path with one obstacle elimination at position (3,2) is 6. Such
 * path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * grid = 
 * [[0,1,1],
 * [1,1,1],
 * [1,0,0]], 
 * k = 1
 * Output: -1
 * Explanation: 
 * We need to eliminate at least two obstacles to find such a walk.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * grid.length == m
 * grid[0].length == n
 * 1 <= m, n <= 40
 * 1 <= k <= m*n
 * grid[i][j] == 0 or 1
 * grid[0][0] == grid[m-1][n-1] == 0
 * 
 */

// @lc code=start
class Solution {
    typedef array<int, 3> Element;
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int X = grid.size();
        int Y = X ? grid[0].size() : 0;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        Element p;
        p[0] = 0;
        p[1] = 0;
        p[2] = k;
        queue<Element> q;
        q.push(p);
        set<Element> visited;
        visited.insert(p);
        int result = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz-- > 0)
            {
                p = q.front();
                q.pop();
                int x = p[0];
                int y = p[1];
                int z = p[2];
                if (x + 1 == X and y + 1 == Y)
                {
                    return result;
                }
                for (int i = 0; i < 4; ++i)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (0 <= nx and nx < X and 0 <= ny and ny < Y)
                    {
                        if (grid[nx][ny] == 0)
                        {
                            Element np;
                            np[0] = nx;
                            np[1] = ny;
                            np[2] = z;
                            if (!visited.count(np))
                            {
                                visited.insert(np);
                                q.push(np);
                            }
                        }
                        else if (z > 0)
                        {
                            Element np;
                            np[0] = nx;
                            np[1] = ny;
                            np[2] = z - 1;
                            if (!visited.count(np))
                            {
                                visited.insert(np);
                                q.push(np);
                            }
                        }
                    }
                }
            }
            ++result;
        }
        return -1;
    }
};
// @lc code=end