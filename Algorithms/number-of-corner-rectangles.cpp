// 750. Number Of Corner Rectangles
// https://leetcode.com/problems/number-of-corner-rectangles/

/*
Given a grid where each entry is only 0 or 1, find the number of corner rectangles.

A corner rectangle is 4 distinct 1s on the grid that form an axis-aligned rectangle. Note that only the corners need to have the value 1. Also, all four 1s used must be distinct.

Example 1:
Input: grid = 
[[1, 0, 0, 1, 0],
 [0, 0, 1, 0, 1],
 [0, 0, 0, 1, 0],
 [1, 0, 1, 0, 1]]
Output: 1
Explanation: There is only one corner rectangle, with corners grid[1][2], grid[1][4], grid[3][2], grid[3][4].
Example 2:
Input: grid = 
[[1, 1, 1],
 [1, 1, 1],
 [1, 1, 1]]
Output: 9
Explanation: There are four 2x2 rectangles, four 2x3 and 3x2 rectangles, and one 3x3 rectangle.
Example 3:
Input: grid = 
[[1, 1, 1, 1]]
Output: 0
Explanation: Rectangles must have four distinct corners.
Note:
The number of rows and columns of grid will each be in the range [1, 200].
Each grid[i][j] will be either 0 or 1.
The number of 1s in the grid will be at most 6000.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countCornerRectangles(vector<vector<int>> & grid) {
        int result = 0, x = grid.size(), y = x == 0 ? 0 : grid[0].size(), i = 0, j = 0;
        if (x < 2 or y < 2) {
            return 0;
        }
        vector<vector<int>> A(y);
        vector<int> B;
        j = y - 1;
        while (j >= 0) {
            if (grid[x - 1][j]) {
                A[j].push_back(x - 1);
            }
            --j;
        }
        i = x - 2;
        while (i >= 0) {
            B.clear();
            j = y - 1;
            while (j >= 0) {
                if (grid[i][j]) {
                    for (const auto & k : B) {
                        if (grid[i][k]) {
                            for (const auto & l : A[j]) {
                                if (grid[l][k]) {
                                    ++result;
                                }
                            }
                        }
                    }
                    A[j].push_back(i);
                    B.push_back(j);
                }
                --j;
            }
            --i;
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<vector<int>> grid;
    int result;
    
    grid = {{1, 0, 0, 1, 0}, {0, 0, 1, 0, 1}, {0, 0, 0, 1, 0}, {1, 0, 1, 0, 1}};
    result = solution.countCornerRectangles(grid);
    cout << result << '\n';

    grid = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    result = solution.countCornerRectangles(grid);
    cout << result << '\n';

    grid = {{1, 1, 1, 1}};
    result = solution.countCornerRectangles(grid);
    cout << result << '\n';
    
    return 0;
}