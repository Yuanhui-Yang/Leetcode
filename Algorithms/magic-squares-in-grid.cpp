840. Magic Squares In Grid
https://leetcode.com/problems/magic-squares-in-grid/

A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).

 

Example 1:

Input: [[4,3,8,4],
        [9,5,1,9],
        [2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:
438
951
276

while this one is not:
384
519
762

In total, there is only one magic square inside the given grid.
Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
0 <= grid[i][j] <= 15

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int X = grid.size(), Y = X ? grid[0].size() : 0, result = 0;
        array<int, 3> rows, columns;
        array<int, 2> diagonals;
        for (int x = 0; x + 3 <= X; ++x)
        {
            for (int y = 0; y + 3 <= Y; ++y)
            {
                int mask = 0;
                rows.fill(0);
                columns.fill(0);
                diagonals.fill(0);
                for (int i = 0; i < 3; ++i)
                {
                    int val = 0;
                    for (int j = 0; j < 3; ++j)
                    {
                        val = grid[x + i][y + j];
                        if (1 <= val and val <= 9)
                        {
                            mask |= (1 << (val - 1));
                        }
                        rows[i] += val;
                        columns[j] += val;
                    }
                    val = grid[x + i][y + i];
                    diagonals[0] += val;
                    val = grid[x + i][y + 2 - i];
                    diagonals[1] += val;
                }
                int sum = rows[0];
                if (mask + 1 == (1 << 9) and sum == rows[1] and sum == rows[2] and sum == columns[0] and sum == columns[1] and sum == columns[2] and sum == diagonals[0] and sum == diagonals[1])
                {
                    ++result;
                }
            }
        }
        return result;
    }
};