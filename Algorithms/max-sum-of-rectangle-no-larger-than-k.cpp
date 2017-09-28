// 363. Max Sum of Rectangle No Larger Than K
// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

/*
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:
Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2
The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

Note:
The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?
*/

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;

class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		int X = matrix.size(), Y = X == 0 ? 0 : matrix[0].size(), result = INT_MIN, i = 0, j = 0, l = 0, m = 0, curr = 0;
		set<int> A;
		set<int>::iterator a, b;
		vector<int> B;
		for (i = 0; i < X; ++i) {
			B.clear();
			B.resize(Y, 0);
			for (j = i; j < X; ++j) {
				for (l = 0; l < Y; ++l) {
					B[l] += matrix[j][l];
				}
				A.clear();
				A.insert(0);
				curr = 0;
				for (l = 0; l < Y; ++l) {
					curr += B[l];
					a = A.lower_bound(curr - k);
					b = end(A);
					if (a != b) {
						m = curr - *a;
						if (m <= k and result < m) {
							result = m;
						}
					}
					A.insert(curr);
				}
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<vector<int>> matrix;
	int k, result;

	k = 2;
	matrix = {{1, 0, 1}, {0, -2, 3}};
	result = solution.maxSumSubmatrix(matrix, k);
	cout << result << '\n';

	k = 2;
	matrix = {{2, 2, -1}};
	result = solution.maxSumSubmatrix(matrix, k);
	cout << result << '\n';
	
	return 0;
}