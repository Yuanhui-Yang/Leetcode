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
                        array<int, 3> p = {i, j, 0};
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
                        if (cell == '.') {
                            int nz = z;
                            if (unseen[nx][ny][nz]) {
                                array<int, 3> to = {nx, ny, nz};
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
                                    array<int, 3> to = {nx, ny, nz};
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
                                        array<int, 3> to = {nx, ny, nz};
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