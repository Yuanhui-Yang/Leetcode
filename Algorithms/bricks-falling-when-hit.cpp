803. Bricks Falling When Hit
https://leetcode.com/problems/bricks-falling-when-hit/

We have a grid of 1s and 0s; the 1s in a cell represent bricks.  A brick will not drop if and only if it is directly connected to the top of the grid, or at least one of its (4-way) adjacent bricks will not drop.

We will do some erasures sequentially. Each time we want to do the erasure at the location (i, j), the brick (if it exists) on that location will disappear, and then some other bricks may drop because of that erasure.

Return an array representing the number of bricks that will drop after each erasure in sequence.

Example 1:
Input: 
grid = [[1,0,0,0],[1,1,1,0]]
hits = [[1,0]]
Output: [2]
Explanation: 
If we erase the brick at (1, 0), the brick at (1, 1) and (1, 2) will drop. So we should return 2.
Example 2:
Input: 
grid = [[1,0,0,0],[1,1,0,0]]
hits = [[1,1],[1,0]]
Output: [0,0]
Explanation: 
When we erase the brick at (1, 0), the brick at (1, 1) has already disappeared due to the last move. So each erasure will cause no bricks dropping.  Note that the erased brick (1, 0) will not be counted as a dropped brick.
 

Note:

The number of rows and columns in the grid will be in the range [1, 200].
The number of erasures will not exceed the area of the grid.
It is guaranteed that each erasure will be different from any other erasure, and located inside the grid.
An erasure may refer to a location with no brick - if it does, no bricks drop.

#include <iostream>
#include <array>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        X = grid.size();
        Y = X ? grid[0].size() : 0;
        Z = X * Y;
        root.resize(Z + 1);
        iota(root.begin(), root.end(), 0);
        size.resize(Z + 1, 1);
        dx = {0, -1, 0, 1};
        dy = {-1, 0, 1, 0};
        for (const auto & hit : hits) {
            int x = hit[0], y = hit[1], & z = grid[x][y];
            if (z == 1) {
                z = 2;
            }
        }
        for (int i = 0; i < X; ++i) {
            for (int j = 0; j < Y; ++j) {
                if (grid[i][j] == 1) {
                    unoinAround(grid, i, j);
                }
            }
        }
        int sz = hits.size(), prev = size[find(Z)];
        vector<int> result(sz, 0);
        for (int i = sz - 1; i >= 0; --i) {
            int x = hits[i][0], y = hits[i][1], & z = grid[x][y];
            if (z == 2) {
                z = 1;
                unoinAround(grid, x, y);
            }
            int curr = size[find(Z)];
            result[i] = max(0, curr - prev - 1);
            prev = curr;
        }
        return result;
    }
private:
    int X, Y, Z;
    vector<int> root, size;
    array<int, 4> dx, dy;
    int find(int id) {
        while (id != root[id]) {
            root[id] = root[root[id]];
            id = root[id];
        }
        return id;
    }
    void unoin(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) {
            return;
        }
        if (rx == Z) {
            swap(rx, ry);
        }
        else if (size[rx] > size[ry]) {
            swap(rx, ry);
        }
        root[rx] = ry;
        size[ry] += size[rx];
    }
    int getId(int x, int y) {
        return x * Y + y;
    }
    void unoinAround(vector<vector<int>>& grid, int x, int y) {
        int a = getId(x, y);
        if (x == 0) {
            unoin(a, Z);
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 and nx < X and ny >= 0 and ny < Y and grid[nx][ny] == 1) {
                int b = getId(nx, ny);
                unoin(a, b);
            }
        }
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>> grid, hits;
    vector<int> result;
    
    grid = {{1, 0, 0, 0}, {1, 1, 1, 0}};
    hits = {{1, 0}};
    result = solution.hitBricks(grid, hits);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';
    
    grid = {{1, 0, 0, 0}, {1, 1, 0, 0}};
    hits = {{1, 1}, {1, 0}};
    result = solution.hitBricks(grid, hits);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';
    
    return 0;
}
