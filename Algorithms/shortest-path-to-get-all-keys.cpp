864. Shortest Path to Get All Keys
https://leetcode.com/problems/shortest-path-to-get-all-keys/

We are given a 2-dimensional grid. "." is an empty cell, "#" is a wall, "@" is the starting point, ("a", "b", ...) are keys, and ("A", "B", ...) are locks.

We start at the starting point, and one move consists of walking one space in one of the 4 cardinal directions.  We cannot walk outside the grid, or walk into a wall.  If we walk over a key, we pick it up.  We can't walk over a lock unless we have the corresponding key.

For some 1 <= K <= 6, there is exactly one lowercase and one uppercase letter of the first K letters of the English alphabet in the grid.  This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

Return the lowest number of moves to acquire all keys.  If it's impossible, return -1.

 

Example 1:

Input: ["@.a.#","###.#","b.A.B"]
Output: 8
Example 2:

Input: ["@..aA","..B#.","....b"]
Output: 6
 

Note:

1 <= grid.length <= 30
1 <= grid[0].length <= 30
grid[i][j] contains only '.', '#', '@', 'a'-'f' and 'A'-'F'
The number of keys is in [1, 6].  Each key has a different letter and opens exactly one lock.

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <array>
#include <cctype>

using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int X = grid.size(), Y = X == 0 ? 0 : grid[0].size(), destination = 0;
        queue<array<int, 3>> q;
        vector<vector<vector<bool>>> unseen(X, vector<vector<bool>>(Y, vector<bool>(64, true)));
        for (int i = 0; i < X; ++i) {
            for (int j = 0; j < Y; ++j) {
                char cell = grid[i][j];
                if (cell == '@') {
                    if (unseen[i][j][0]) {
                        array<int, 3> p{{i, j, 0}};
                        q.push(p);
                        unseen[i][j][0] = false;
                    }
                }
                else if (islower(cell)) {
                    int offset = cell - 'a';
                    int mask = 1 << offset;
                    destination |= mask;
                }
            }
        }
        int step = 0, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; 
        while (!q.empty()) {
            int sz = q.size();
            while (sz-- > 0) {
                array<int, 3> from = q.front();
                q.pop();
                if (from[2] == destination) {
                    return step;
                }
                int x = from[0], y = from[1], z = from[2];
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 and nx < X and ny >= 0 and ny < Y) {
                        char cell = grid[nx][ny];
                        if (cell == '.' or cell == '@') {
                            int nz = z;
                            if (unseen[nx][ny][nz]) {
                                array<int, 3> to{{nx, ny, nz}};
                                unseen[nx][ny][nz] = false;
                                q.push(to);
                            }
                        }
                        else if (isalpha(cell)) {
                            if (islower(cell)) {
                                int offset = cell - 'a';
                                int mask = 1 << offset;
                                int nz = z | mask;
                                if (unseen[nx][ny][nz]) {
                                    array<int, 3> to{{nx, ny, nz}};
                                    unseen[nx][ny][nz] = false;
                                    q.push(to);
                                }
                            }
                            else {
                                int offset = cell - 'A';
                                int mask = 1 << offset;
                                if (mask & z) {
                                    int nz = z;
                                    if (unseen[nx][ny][nz]) {
                                        array<int, 3> to{{nx, ny, nz}};
                                        unseen[nx][ny][nz] = false;
                                        q.push(to);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};

int main(void) {
    Solution solution;
    vector<string> grid;
    int result = 0;

    grid = {"@...a", ".###A", "b.BCc"};
    result = solution.shortestPathAllKeys(grid);
    cout << result << '\n';

    return 0;
}
