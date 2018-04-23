764. Largest Plus Sign
https://leetcode.com/problems/largest-plus-sign/

In a 2D grid from (0, 0) to (N-1, N-1), every cell contains a 1, except those cells in the given list mines which are 0. What is the largest axis-aligned plus sign of 1s contained in the grid? Return the order of the plus sign. If there is none, return 0.

An "axis-aligned plus sign of 1s of order k" has some center grid[x][y] = 1 along with 4 arms of length k-1 going up, down, left, and right, and made of 1s. This is demonstrated in the diagrams below. Note that there could be 0s or 1s beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1s.

Examples of Axis-Aligned Plus Signs of Order k:

Order 1:
000
010
000

Order 2:
00000
00100
01110
00100
00000

Order 3:
0000000
0001000
0001000
0111110
0001000
0001000
0000000
Example 1:

Input: N = 5, mines = [[4, 2]]
Output: 2
Explanation:
11111
11111
11111
11111
11011
In the above grid, the largest plus sign can only be order 2.  One of them is marked in bold.
Example 2:

Input: N = 2, mines = []
Output: 1
Explanation:
There is no plus sign of order 2, but there is of order 1.
Example 3:

Input: N = 1, mines = [[0, 0]]
Output: 0
Explanation:
There is no plus sign, so return 0.
Note:

N will be an integer in the range [1, 500].
mines will have length at most 5000.
mines[i] will be length 2 and consist of integers in the range [0, N-1].
(Additionally, programs submitted in C, C++, or C# will be judged with a slightly smaller time limit.)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> A(N, vector<int>(N, N));
        for (const auto & mine : mines) {
            A[mine[0]][mine[1]] = 0;
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0, left = 0; j < N; ++j) {
                left = A[i][j] ? left + 1 : 0;
                A[i][j] = min(A[i][j], left);
            }
        }
        for (int j = 0; j < N; ++j) {
            for (int i = 0, top = 0; i < N; ++i) {
                top = A[i][j] ? top + 1 : 0;
                A[i][j] = min(A[i][j], top);
            }
        }
        for (int i = N - 1; i >= 0; --i) {
            for (int j = N - 1, right = 0; j >= 0; --j) {
                right = A[i][j] ? right + 1 : 0;
                A[i][j] = min(A[i][j], right);
            }
        }
        for (int j = N - 1; j >= 0; --j) {
            for (int i = N - 1, bottom = 0; i >= 0; --i) {
                bottom = A[i][j] ? bottom + 1 : 0;
                A[i][j] = min(A[i][j], bottom);
            }
        }
        int result = 0;
        for (const auto & i : A) {
            for (const auto & j : i) {
                result = max(result, j);
            }
        }
        return result;
    }
};

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> board(N, vector<int>(N, 1)), left(N, vector<int>(N, 0)), right(left), top(left), bottom(left);
        for (const auto & mine : mines) {
            board[mine[0]][mine[1]] = 0;
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == 1) {
                    if (i == 0) {
                        top[i][j] = 1;
                    }
                    else {
                        top[i][j] = top[i - 1][j] + 1;
                    }
                    if (j == 0) {
                        left[i][j] = 1;
                    }
                    else {
                        left[i][j] = left[i][j - 1] + 1;
                    }
                }
            }
        }
        for (int i = N - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                if (board[i][j] == 1) {
                    if (i == N - 1) {
                        bottom[i][j] = 1;
                    }
                    else {
                        bottom[i][j] = bottom[i + 1][j] + 1;
                    }
                    if (j == N - 1) {
                        right[i][j] = 1;
                    }
                    else {
                        right[i][j] = right[i][j + 1] + 1;
                    }   
                }
            }
        }
        int result = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == 1) {
                    int len = left[i][j];
                    len = min(len, right[i][j]);
                    len = min(len, top[i][j]);
                    len = min(len, bottom[i][j]);
                    result = max(result, len);
                }
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    int N, result;
    vector<vector<int>> mines;

    N = 5;
    mines = {{4, 2}};
    result = solution.orderOfLargestPlusSign(N, mines);
    cout << result << '\n';

    N = 2;
    mines = {};
    result = solution.orderOfLargestPlusSign(N, mines);
    cout << result << '\n';

    N = 1;
    mines = {{0, 0}};
    result = solution.orderOfLargestPlusSign(N, mines);
    cout << result << '\n';

    return 0;
}
