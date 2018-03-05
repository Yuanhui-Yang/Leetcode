305. Number of Islands II
https://leetcode.com/problems/number-of-islands-ii/

A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]

Challenge:

Can you do it in time complexity O(k log mn), where k is the length of the positions?

#include <iostream>
#include <vector>
#include <utility>
#include <array>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> A(m * n, 0);
        iota(A.begin(), A.end(), 0);
        vector<vector<bool>> B(m, vector<bool>(n, false));
        vector<int> result;
        int cnt = 0;
        for (const auto & position : positions) {
            f1(A, B, cnt, m, n, position.first, position.second);
            result.push_back(cnt);
        }
        return result;
    }
private:
    void f1(vector<int> & A, vector<vector<bool>> & B, int & cnt, int m, int n, int x, int y) {
        if (x < 0 or x >= m or y < 0 or y >= n or B[x][y]) {
            return;
        }
        array<int, 4> dx{-1, 0, 1, 0}, dy{0, -1, 0, 1};
        ++cnt;
        B[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 and nx < m and ny >= 0 and ny < n and B[nx][ny]) {
                int a = f3(A, y + x * n), b = f3(A, ny + nx * n);
                if (a != b) {
                    A[a] = b;
                    --cnt;
                }
            }
        }
    }
    int f2(vector<int> & A, int id) {
        return A[id] == id ? id : A[id] = f2(A, A[id]);
    }
    int f3(vector<int> & A, int id) {
        while (id != A[id]) {
            A[id] = A[A[id]];
            id = A[id];
        }
        return id;
    }
};

int main(void) {
    Solution solution;
    int m, n;
    vector<pair<int, int>> positions;
    vector<int> result;

    m = 3;
    n = 3;
    positions = {{0, 0}, {0, 1}, {1, 2}, {2, 1}};
    result = solution.numIslands2(m, n, positions);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    return 0;
}