// 363. Max Sum of Rectangle No Larger Than K
// https://leetcode.com/problems/max-sum-of-sub-matrix-no-larger-than-k/
#include <iostream>
#include <casssert>
#include <vector>
using namespace std;
class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

	}
};
int main(void) {
	Solution solution;
	int result = 0;
	vector<vector<int>> matrix;
	
	matrix = {{1, 0, 1}, {0, -2, 3}};
	result = solution.maxSumSubmatrix(matrix, 2);
	assert(2 == result);
	
	cout << "\nPassed All\n";
	return 0;
}