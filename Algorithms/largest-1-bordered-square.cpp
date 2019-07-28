1139. Largest 1-Bordered Square
https://leetcode.com/problems/largest-1-bordered-square/

Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.

 

Example 1:

Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 9
Example 2:

Input: grid = [[1,1,0,0]]
Output: 1
 

Constraints:

1 <= grid.length <= 100
1 <= grid[0].length <= 100
grid[i][j] is 0 or 1

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int X = grid.size(), Y = X ? grid[0].size() : 0;
        vector<vector<int>> A(X, vector<int>(Y + 1, 0)), B(Y, vector<int>(X + 1, 0));
        for (int i = 0; i < X; ++i)
        {
            for (int j = 0; j < Y; ++j)
            {
                A[i][j + 1] = A[i][j] + grid[i][j];
            }
        }
        for (int j = 0; j < Y; ++j)
        {
            for (int i = 0; i < X; ++i)
            {
                B[j][i + 1] = B[j][i] + grid[i][j];
            }
        }
        for (int len = min(X, Y); len > 0; --len)
        {
            for (int i = 0; i + len <= X; ++i)
            {
                for (int j = 0; j + len <= Y; ++j)
                {
                    if (
                        A[i][j + len] - A[i][j] == len and
                        A[i + len - 1][j + len] - A[i + len - 1][j] == len and
                        B[j][i + len] - B[j][i] == len and
                        B[j + len - 1][i + len] - B[j + len - 1][i] == len
                    )
                    {
                        return len * len;
                    }
                }
            }
        }
        return 0;
    }
};