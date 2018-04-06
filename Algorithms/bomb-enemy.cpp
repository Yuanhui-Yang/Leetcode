361. Bomb Enemy
https://leetcode.com/problems/bomb-enemy/

Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.

Example:
For the given grid

0 E 0 0
E 0 W E
0 E 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int X = grid.size(), Y = X ? grid[0].size() : 0, result = 0, rows = 0;
        vector<int> cols(Y, 0);
        for (int i = 0; i < X; ++i) {
            for (int j = 0; j < Y; ++j) {
                if (j == 0 or grid[i][j - 1] == 'W') {
                    rows = 0;
                    for (int k = j; k < Y and grid[i][k] != 'W'; ++k) {
                        rows += grid[i][k] == 'E';
                    }
                }
                if (i == 0 or grid[i - 1][j] == 'W') {
                    cols[j] = 0;
                    for (int k = i; k < X and grid[k][j] != 'W'; ++k) {
                        cols[j] += grid[k][j] == 'E';
                    }
                }
                if (grid[i][j] == '0') {
                    result = max(result, rows + cols[j]);
                }
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<vector<char>> grid;
    int result;

    grid = {{'0', 'E', '0', '0'}, {'E', '0', 'W', 'E'}, {'0', 'E', '0', '0'}};
    result = solution.maxKilledEnemies(grid);
    cout << result << '\n';

    return 0;
}
