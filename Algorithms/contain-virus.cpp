749. Contain Virus
https://leetcode.com/problems/contain-virus/

A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.

The world is modeled as a 2-D array of cells, where 0 represents uninfected cells, and 1 represents cells contaminated with the virus. A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.

Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region -- the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night. There will never be a tie.

Can you save the day? If so, what is the number of walls required? If not, and the world becomes fully infected, return the number of walls used.

Example 1:
Input: grid = 
[[0,1,0,0,0,0,0,1],
 [0,1,0,0,0,0,0,1],
 [0,0,0,0,0,0,0,1],
 [0,0,0,0,0,0,0,0]]
Output: 10
Explanation:
There are 2 contaminated regions.
On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:

[[0,1,0,0,0,0,1,1],
 [0,1,0,0,0,0,1,1],
 [0,0,0,0,0,0,1,1],
 [0,0,0,0,0,0,0,1]]

On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.
Example 2:
Input: grid = 
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output: 4
Explanation: Even though there is only one cell saved, there are 4 walls built.
Notice that walls are only built on the shared boundary of two different cells.
Example 3:
Input: grid = 
[[1,1,1,0,0,0,0,0,0],
 [1,0,1,0,1,1,1,1,1],
 [1,1,1,0,0,0,0,0,0]]
Output: 13
Explanation: The region on the left only builds two new walls.
Note:
The number of rows and columns of grid will each be in the range [1, 50].
Each grid[i][j] will be either 0 or 1.
Throughout the described process, there is always a contiguous viral region that will infect strictly more uncontaminated squares in the next round.

#include <iostream>
#include <vector>
#include <tuple>
#include <array>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int containVirus(vector<vector<int>>& grid) {
        int result = 0;
        while (true) {
            tuple<int, int, array<int, 2>> t = f1(grid, 1, 2);
            if (get<0>(t) <= 0) {
                return result;
            }
            else {
                result += get<1>(t);
                f2(grid, get<2>(t), -1);
                f3(grid, 2, 1);
            }
        }
        return 0;
    }
private:
    tuple<int, int, array<int, 2>> f1(vector<vector<int>> & grid, int from, int to) {
        int X = grid.size(), Y = X == 0 ? 0 : grid[0].size();
        tuple<int, int, array<int, 2>> result({-1, -1, {-1, -1}});
        for (int i = 0; i < X; ++i) {
            for (int j = 0; j < Y; ++j) {
                if (grid[i][j] == from) {
                    tuple<int, int, array<int, 2>> curr = f4(grid, {i, j}, to);
                    if (get<0>(result) < 0 or get<0>(result) < get<0>(curr)) {
                        result = curr;
                    }
                }
            }
        }
        return result;
    }
    void f2(vector<vector<int>> & grid, array<int, 2> & pos, int to) {
        int from = grid[pos[0]][pos[1]];
        if (from == to) {
            return;
        }
        queue<array<int, 2>> q;
        q.push(pos);
        grid[pos[0]][pos[1]] = to;
        array<int, 4> dx({0, -1, 0, 1}), dy({-1, 0, 1, 0});
        int X = grid.size(), Y = X == 0 ? 0 : grid[0].size();
        while (!q.empty()) {
            array<int, 2> p = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                p[0] += dx[i];
                p[1] += dy[i];
                if (p[0] >= 0 and p[0] < X and p[1] >= 0 and p[1] < Y) {
                    if (grid[p[0]][p[1]] == from) {
                        grid[p[0]][p[1]] = to;
                        q.push(p);
                    }
                }
                p[0] -= dx[i];
                p[1] -= dy[i];
            }
        }
    }
    void f3(vector<vector<int>> & grid, int from, int to) {
        int X = grid.size(), Y = X == 0 ? 0 : grid[0].size();
        array<int, 4> dx({0, -1, 0, 1}), dy({-1, 0, 1, 0});
        for (int i = 0; i < X; ++i) {
            for (int j = 0; j < Y; ++j) {
                if (grid[i][j] == from) {
                    grid[i][j] = to;
                    queue<array<int, 2>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        array<int, 2> p = q.front();
                        q.pop();
                        for (int i = 0; i < 4; ++i) {
                            p[0] += dx[i];
                            p[1] += dy[i];
                            if (p[0] >= 0 and p[0] < X and p[1] >= 0 and p[1] < Y) {
                                if (grid[p[0]][p[1]] == from) {
                                    grid[p[0]][p[1]] = to;
                                    q.push(p);
                                }
                                else if (grid[p[0]][p[1]] == 0) {
                                    grid[p[0]][p[1]] = to;
                                }
                            }
                            p[0] -= dx[i];
                            p[1] -= dy[i];
                        }
                    }
                }
            }
        }
    }
    tuple<int, int, array<int, 2>> f4(vector<vector<int>> & grid, array<int, 2> pos, int to) {
        int X = grid.size(), Y = X == 0 ? 0 : grid[0].size(), from = grid[pos[0]][pos[1]], wall = 0;
        if (from == to) {
            return {-1, -1, {-1, -1}};
        }
        queue<array<int, 2>> q;
        q.push(pos);
        array<int, 4> dx({-1, 0, 1, 0}), dy({0, -1, 0, 1});
        grid[pos[0]][pos[1]] = to;
        set<array<int, 2>> uninfected;
        while (!q.empty()) {
            array<int, 2> p = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                p[0] += dx[i];
                p[1] += dy[i];
                if (p[0] >= 0 and p[0] < X and p[1] >= 0 and p[1] < Y) {
                    if (grid[p[0]][p[1]] == from) {
                        q.push(p);
                        grid[p[0]][p[1]] = to;
                    }
                    else if (grid[p[0]][p[1]] == 0) {
                        uninfected.insert(p);
                        ++wall;
                    }
                }
                p[0] -= dx[i];
                p[1] -= dy[i];
            }
        }
        return {uninfected.size(), wall, pos};
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>> grid;
    int result;
    
    grid = {{0, 1, 0, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}};
    result = solution.containVirus(grid);
    cout << result << '\n';

    grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    result = solution.containVirus(grid);
    cout << result << '\n';

    grid = {{1, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 0, 1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0, 0, 0}};
    result = solution.containVirus(grid);
    cout << result << '\n';
    
    return 0;
}