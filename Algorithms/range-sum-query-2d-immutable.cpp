304. Range Sum Query 2D - Immutable
https://leetcode.com/problems/range-sum-query-2d-immutable/

Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int X = matrix.size(), Y = X == 0 ? 0 : matrix[0].size();
        A.resize(X + 1, vector<int>(Y + 1, 0));
        for (int i = 0; i < X; ++i) {
            int sum = 0;
            for (int j = 0; j < Y; ++j) {
                sum += matrix[i][j];
                A[i + 1][j + 1] = sum + A[i][j + 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return A[row2 + 1][col2 + 1] - A[row2 + 1][col1] - A[row1][col2 + 1] + A[row1][col1];
    }
private:
    vector<vector<int>> A;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

int main(void) {
    vector<vector<int>> matrix;
    int result;
    
    matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    NumMatrix obj(matrix);
    result = obj.sumRegion(2, 1, 4, 3);
    cout << result << '\n';
    result = obj.sumRegion(1, 1, 2, 2);
    cout << result << '\n';
    result = obj.sumRegion(1, 2, 2, 4);
    cout << result << '\n';
    
    return 0;
}