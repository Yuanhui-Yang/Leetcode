1102. Path With Maximum Minimum Value
https://leetcode.com/problems/path-with-maximum-minimum-value/

Given a matrix of integers A with R rows and C columns, find the maximum score of a path starting at [0,0] and ending at [R-1,C-1].

The score of a path is the minimum value in that path.  For example, the value of the path 8 →  4 →  5 →  9 is 4.

A path moves some number of times from one visited cell to any neighbouring unvisited cell in one of the 4 cardinal directions (north, east, west, south).

 

Example 1:



Input: [[5,4,5],[1,2,6],[7,4,6]]
Output: 4
Explanation: 
The path with the maximum score is highlighted in yellow. 
Example 2:



Input: [[2,2,1,2,2,2],[1,2,2,2,1,2]]
Output: 2
Example 3:



Input: [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
Output: 3
 

Note:

1 <= R, C <= 100
0 <= A[i][j] <= 10^9

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int X = A.size(), Y = X ? A[0].size() : 0;
        vector<vector<int>> B(X, vector<int>(Y, 0));
        B[0][0] = A[0][0];
        queue<array<int, 3>> q;
        q.push({0, 0, A[0][0]});
        array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
        while (!q.empty())
        {
            array<int, 3> from = q.front();
            q.pop();
            int x = from[0], y = from[1], z = from[2];
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (0 <= nx and nx < X and 0 <= ny and ny < Y)
                {
                    int nz = min(z, A[nx][ny]);
                    if (B[nx][ny] < nz)
                    {
                        B[nx][ny] = nz;
                        q.push({nx, ny, nz});
                    }
                }
            }
        }
        return B[X - 1][Y - 1];
    }
};