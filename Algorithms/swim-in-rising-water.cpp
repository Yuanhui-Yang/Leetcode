778. Swim in Rising Water
https://leetcode.com/problems/swim-in-rising-water/

On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?

Example 1:

Input: [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.

You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:

Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

The final route is marked in bold.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
Note:

2 <= N <= 50.
grid[i][j] is a permutation of [0, ..., N*N - 1].

#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        array<int, 2> p = f2(grid);
        int i = p[0], j = p[1] + 1;
        while (i < j) {
            int k = i + (j - i) / 2;
            if (f1(grid, k)) {
                j = k;
            }
            else {
                i = k + 1;
            }
        }
        return i;
    }
private:
    bool f1(vector<vector<int>> grid, int t) {
        int X = grid.size(), Y = X == 0 ? 0 : grid[0].size();
        if (X == 0 or Y == 0 or grid[0][0] > t) {
            return false;
        }
        array<int, 2> begin({0, 0}), end({X - 1, Y - 1});
        queue<array<int, 2>> q;
        q.push(begin);
        grid[0][0] = INT_MIN;
        array<int, 4> dx({0, -1, 0, 1}), dy({-1, 0, 1, 0});
        while (!q.empty()) {
            array<int, 2> p = q.front();
            if (p == end) {
                return true;
            }
            q.pop();
            for (int i = 0; i < 4; ++i) {
                p[0] += dx[i];
                p[1] += dy[i];
                if (p[0] >= 0 and p[0] < X and p[1] >= 0 and p[1] < Y) {
                    if (grid[p[0]][p[1]] != INT_MIN and grid[p[0]][p[1]] <= t) {
                        grid[p[0]][p[1]] = INT_MIN;
                        q.push(p);
                    }
                }
                p[0] -= dx[i];
                p[1] -= dy[i];                
            }
        }
        return false;
    }
    array<int, 2> f2(vector<vector<int>> & grid) {
        array<int, 2> result;
        result[0] = INT_MAX;
        result[1] = INT_MIN;
        for (const auto & i : grid) {
            for (const auto & j : i) {
                result[0] = min(result[0], j);
                result[1] = max(result[1], j);
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>> grid;
    int result;
    
    grid = {{0, 2}, {1, 3}};
    result = solution.swimInWater(grid);
    cout << result << '\n';

    grid = {{0, 1, 2, 3, 4}, {24, 23, 22, 21, 5}, {12, 13, 14, 15, 16}, {11, 17, 18, 19, 20}, {10, 9, 8, 7, 6}};
    result = solution.swimInWater(grid);
    cout << result << '\n';
    
    return 0;
}