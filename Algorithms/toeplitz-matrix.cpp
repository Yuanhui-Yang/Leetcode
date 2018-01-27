766. Toeplitz Matrix
https://leetcode.com/problems/toeplitz-matrix/

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 

Example 1:

Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: True
Explanation:
1234
5123
9512

In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]", and in each diagonal all elements are the same, so the answer is True.
Example 2:

Input: matrix = [[1,2],[2,2]]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.
Note:

matrix will be a 2D array of integers.
matrix will have a number of rows and columns in range [1, 20].
matrix[i][j] will be integers in range [0, 99].

#include <iostream>
#include <array>
#include <vector>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int X = matrix.size(), Y = X == 0 ? 0 : matrix[0].size(), i;
        for (i = 0; i < Y; ++i) {
            if (!f1(matrix, {0, i})) {
                return false;
            }
        }
        for (i = 1; i < X; ++i) {
            if (!f1(matrix, {i, 0})) {
                return false;
            }
        }
        return true;
    }
private:
    bool f1(vector<vector<int>> & matrix, array<int, 2> pos) {
        int X = matrix.size(), Y = X == 0 ? 0 : matrix[0].size(), i, j;
        for (i = pos[0] + 1, j = pos[1] + 1; i < X and j < Y; ++i, ++j) {
            if (matrix[i][j] != matrix[pos[0]][pos[1]]) {
                return false;
            }
        }
        return true;
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>> matrix;
    bool result;
    
    matrix = {{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};
    result = solution.isToeplitzMatrix(matrix);
    cout << boolalpha << result << '\n';
    
    matrix = {{1, 2}, {2, 2}};
    result = solution.isToeplitzMatrix(matrix);
    cout << boolalpha << result << '\n';  
    
    return 0;
}