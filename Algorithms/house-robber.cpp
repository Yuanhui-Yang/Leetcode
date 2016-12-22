// 198. House Robber
// https://leetcode.com/problems/house-robber/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		const int nums_size = nums.size();
		if (nums_size == 0) return 0;
		vector<int> OPT(nums_size, 0);
		OPT[0] = nums[0];
		OPT[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nums_size; i++) {
			OPT[i] = max(OPT[i - 2] + nums[i], OPT[i - 1]);
		}
		return OPT[nums_size - 1];
	}
};
int main(void) {
	Solution solution;
	vector<int> nums;
	int result = 0;
	result = solution.rob(nums);
	assert(0 == result);
	cout << "\nPassed All\n";
	return 0;
}