54. Spiral Matrix
https://leetcode.com/problems/spiral-matrix/

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int X = matrix.size(), Y = X == 0 ? 0 : matrix[0].size(), x1 = 0, x2 = X - 1, y1 = 0, y2 = Y - 1;
        while (x1 <= x2 and y1 <= y2) {
            for (int j = y1; j <= y2; ++j) {
                result.push_back(matrix[x1][j]);
            }
            for (int i = x1 + 1; i <= x2; ++i) {
                result.push_back(matrix[i][y2]);
            }
            if (x1 < x2 and y1 < y2) {
                for (int j = y2 - 1; j >= y1; --j) {
                    result.push_back(matrix[x2][j]);
                }
                for (int i = x2 - 1; i > x1; --i) {
                    result.push_back(matrix[i][y1]);
                }
            }
            ++x1;
            --x2;
            ++y1;
            --y2;
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>> matrix;
    vector<int> result;

    matrix = {{ 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }};
    result = solution.spiralOrder(matrix);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    return 0;
}