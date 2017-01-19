// 363. Max Sum of Rectangle No Larger Than K
// https://leetcode.com/problems/max-sum-of-sub-matrix-no-larger-than-k/
#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <climits>
using namespace std;
// BEGIN: http://www.cnblogs.com/grandyang/p/5617660.html
class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		if (matrix.empty() || matrix.front().empty()) {
			return 0;
		}
		for (size_t i = 0; i < matrix.size(); i++) {
			for (size_t j = 1; j < matrix.front().size(); j++) {
				matrix[i][j] += matrix[i][j - 1];
			}
		}
		int result = INT_MIN;
		for (size_t i = 0; i < matrix.front().size(); i++) {
			for (size_t j = i; j < matrix.front().size(); j++) {
				int cumsum = 0;
				set<int> rbtree;
				for (size_t r = 0; r < matrix.size(); r++) {
					cumsum += i ? matrix[r][j] - matrix[r][i - 1] : matrix[r][j];
					if (cumsum < k) {
						result = max(result, cumsum); 
					}
					if (cumsum == k) {
						return result = k;
					}
					const set<int>::iterator it = rbtree.lower_bound(cumsum - k);
					if (it != end(rbtree)) {
						if (*it == cumsum - k) {
							return k;
						}
						result = max(result, cumsum - *it);
					}
					rbtree.insert(cumsum);
				}
			}
		}
		return result;
	}
};
// END: http://www.cnblogs.com/grandyang/p/5617660.html
int main(void) {
	Solution solution;
	int result = 0;
	vector<vector<int>> matrix;
	
	// matrix = {{1, 0, 1}, {0, -2, 3}};
	// result = solution.maxSumSubmatrix(matrix, 2);
	// assert(2 == result);
	
	matrix = {{2, 2, -1}};
	result = solution.maxSumSubmatrix(matrix, 0);
	assert(-1 == result);

	cout << "\nPassed All\n";
	return 0;
}