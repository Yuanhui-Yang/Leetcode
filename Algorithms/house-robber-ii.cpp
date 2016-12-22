// 213. House Robber II
// https://leetcode.com/problems/house-robber-ii/
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
		if (nums_size == 1) return nums[0];
		if (nums_size == 2) return max(nums[0], nums[1]);
		int result = 0;
		for (int i = 0; i < nums_size; i++) {
			vector<pair<int, bool>> OPT(nums_size, pair<int, bool>(0, false));
			OPT[0] = make_pair(nums[i], true);
			OPT[1] = (nums[i] < nums[(i + 1) % nums_size]) ? make_pair(nums[(i + 1) % nums_size], false) : make_pair(nums[i], true);
			for (int j = 2; j < nums_size; j++) {
				if (j + 1 < nums_size) {
					if (OPT[j - 2].first + nums[(i + j) % nums_size] < OPT[j - 1].first) {
						OPT[j] = OPT[j - 1];
					}
					else {
						OPT[j].first = OPT[j - 2].first + nums[(i + j) % nums_size];
						OPT[j].second = OPT[j - 2].second;
					}
					continue;
				}
				if (j + 1 == nums_size) {
					if (OPT[j - 2].second) {
						OPT[j] = OPT[j - 1];
					}
					else {
						if (OPT[j - 2].first + nums[(i + j) % nums_size] < OPT[j - 1].first) {
							OPT[j] = OPT[j - 1];
						}
						else {
							OPT[j].first = OPT[j - 2].first + nums[(i + j) % nums_size];
							OPT[j].second = OPT[j - 2].second;
						}
					}
					continue;
				}
			}
			result = max(result, OPT[nums_size - 1].first);
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums;
	int result = 0;
	result = solution.rob(nums);
	assert(0 == result);
	nums = {1, 1, 1};
	result = solution.rob(nums);
	assert(1 == result);
	cout << "\nPassed All\n";
	return 0;
}