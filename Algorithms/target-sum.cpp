// 494. Target sum
// https://leetcode.com/problems/target-sum/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		if (nums.empty()) {
			return 0;
		}
		vector<unordered_map<int, size_t>> OPT(nums.size());
		for (size_t i = 0; i < nums.size(); i++) {
			if (i == 0) {
				OPT[0][nums[0]]++;
				OPT[0][-nums[0]]++;
				continue;
			}
			if (i >= 1) {
				for (const auto &k : OPT[i - 1]) {
					OPT[i][k.first + nums[i]] += k.second;
					OPT[i][k.first - nums[i]] += k.second;
				}
				continue;
			}
		}
		return OPT[nums.size() - 1].count(S) ? OPT[nums.size() - 1][S] : 0;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums;
	int S;
	int result;

	nums = {1, 1, 1, 1, 1};
	S = 3;
	result = solution.findTargetSumWays(nums, S);
	assert(5 == result);

	cout << "\nPassed All\n";
	return 0;
}