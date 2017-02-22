// 525. Contiguous Array
// https://leetcode.com/problems/contiguous-array/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
	int findMaxLength(vector<int>& nums) {

	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	int result = 0;
	int answer = 0;

	nums = {0, 1};
	answer = 2;
	result = solution.findMaxLength(nums);
	assert(answer == result);

	nums = {0, 1, 0};
	answer = 2;
	result = solution.findMaxLength(nums);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}