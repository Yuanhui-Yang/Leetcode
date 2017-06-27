// 118. Pascal's Triangle
// https://leetcode.com/problems/pascals-triangle/

/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result(numRows);
		for (int i = 0; i < numRows; ++i) {
			for (int j = 0; j <= i; ++j) {
				if (j == 0 or j == i) {
					result[i].push_back(1);
				}
				else {
					result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
				}
			}
		}
		return result;
	}
};