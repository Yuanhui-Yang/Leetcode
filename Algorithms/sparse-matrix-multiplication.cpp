311. Sparse Matrix Multiplication
https://leetcode.com/problems/sparse-matrix-multiplication/

Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int X = A.size(), Y = X ? A[0].size() : 0, Z = Y ? B[0].size() : 0;
        vector<vector<int>> C = f1(A), D = f1(B), result(X, vector<int>(Z, 0));
        for (int i = 0; i < X; ++i) {
            for (const auto & j : C[i]) {
                for (const auto & k : D[j]) {
                    result[i][k] += A[i][j] * B[j][k];
                }
            }
        }
        return result;
    }
private:
    vector<vector<int>> f1(vector<vector<int>>& A) {
        int X = A.size(), Y = X ? A[0].size() : 0;
        vector<vector<int>> result(X);
        for (int i = 0; i < X; ++i) {
            for (int j = 0; j < Y; ++j) {
                if (A[i][j]) {
                    result[i].push_back(j);
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int X = A.size(), Y = X ? A[0].size() : 0, Z = Y ? B[0].size() : 0;
        vector<vector<int>> result(X, vector<int>(Z, 0));
        for (int i = 0; i < X; ++i) {
            for (int j = 0; j < Y; ++j) {
                if (A[i][j]) {
                    for (int k = 0; k < Z; ++k) {
                        if (B[j][k]) {
                            result[i][k] += A[i][j] * B[j][k];   
                        }
                    }   
                }
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>> A, B, result;

    A = {{ 1, 0, 0}, {-1, 0, 3}};
    B = {{ 7, 0, 0 }, { 0, 0, 0 }, { 0, 0, 1 }};
    result = solution.multiply(A, B);
    for (const auto & i : result) {
        for (const auto & j : i) {
            cout << j << '\t';
        }
        cout << '\n';
    }

    return 0;
}
