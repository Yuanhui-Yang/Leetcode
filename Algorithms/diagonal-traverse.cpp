// 498. Diagonal Traverse
// https://leetcode.com/problems/diagonal-traverse/

/*
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
Explanation:

Note:
The total number of elements of the given matrix will not exceed 10,000.
*/

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		int P = matrix.size(), Q = P == 0 ? 0 : matrix[0].size();
		vector<int> result;
		if (P == 0 or Q == 0) {
			return result;
		}
		array<int, 2> curr({0, 0});
		for (int i = 0, j = P * Q, d = -1; i < j; ++i) {
			result.push_back(matrix[curr[0]][curr[1]]);
			if (d < 0) {
				--curr[0];
				++curr[1];
				if (curr[1] >= Q) {
					curr[0] += 2;
					--curr[1];
					d = -d;
				}
				else if (curr[0] < 0) {
					++curr[0];
					d = -d;
				}
			}
			else {
				++curr[0];
				--curr[1];
				if (curr[0] >= P) {
					--curr[0];
					curr[1] += 2;
					d = -d;
				}
				else if (curr[1] < 0) {
					++curr[1];
					d = -d;
				}
			}
		}
		return result;
	}
};