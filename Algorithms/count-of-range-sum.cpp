// 327. Count of Range Sum
// https://leetcode.com/problems/count-of-range-sum/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		minmax
	}
};
int main(void) {
	Solution solution;
	vector<int> nums;
	int lower = 0;
	int upper = 0;
	int result = 0;
	int answer = 0;

	nums = {-2, 5, -1};
	lower = -2;
	upper = 2;
	result = solution.countRangeSum(nums, lower, upper);
	answer = 3;
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}