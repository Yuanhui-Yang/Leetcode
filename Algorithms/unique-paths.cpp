62. Unique Paths
https://leetcode.com/problems/unique-paths/

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

#include <iostream>
#include <array>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        array<vector<int>, 2> A;
        A[0].resize(n, 0);
        A[1].resize(n, 0);
        A[1][0] = 1;
        for (int i = 0; i < m; ++i) {
            int x = i % 2, y = 1 - x;
            A[x][0] = A[y][0];
            for (int j = 1; j < n; ++j) {
                A[x][j] = A[x][j - 1] + A[y][j];
            }
        }
        return A[(m - 1) % 2][n - 1];
    }
};

int main(void) {
    Solution solution;
    int m, n, answer, result;

    m = 10;
    n = 10;
    answer = 48620;
    result = solution.uniquePaths(m, n);

    return 0;
}