// 486. Predict the Winner
// https://leetcode.com/problems/predict-the-winner/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		if (nums.size() <= 2) {
			return true;
		}
		return PredictTheWinner(0, 0, 0, nums.size() - 1, nums);
	}
private:
	bool PredictTheWinner(const int x, const int y, const size_t i, const size_t j, const vector<int>& nums) {
		if (i == j) {
			if (x + nums[i] > y) {
				return true;
			}
			return false;
		}
		return !PredictTheWinner(y, x + nums[i], i + 1, j, nums) || !PredictTheWinner(y, x + nums[j], i, j - 1, nums);
	}
};
int main(void) {
	Solution solution;
	vector<int> nums;
	bool result;

	nums = {1, 5, 2};
	result = solution.PredictTheWinner(nums);
	assert(!result);

	nums = {1, 5, 233, 7};
	result = solution.PredictTheWinner(nums);
	assert(result);

	nums = {0};
	result = solution.PredictTheWinner(nums);
	assert(result);

	nums = {1, 1};
	result = solution.PredictTheWinner(nums);
	assert(result);

	nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	result = solution.PredictTheWinner(nums);
	assert(result);

	cout << "\nPassed All\n";
	return 0;
}