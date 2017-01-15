// 485. Max Consecutive Ones
// https://leetcode.com/problems/max-consecutive-ones/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int result = 0;
		for (size_t i = 0, j = 0; i < nums.size(); i++) {
			if (nums[i] == 1) {
				j = i;
				while (i < nums.size() && nums[i] == 1) {
					i++;
				}
				result = max(result, int(i - j));
				continue;
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	int result = 0;
	vector<int> nums;
	nums = {1, 1, 0, 1, 1, 1};
	result = solution.findMaxConsecutiveOnes(nums);
	assert(3 == result);
	cout << "\nPassed all\n";
	return 0;
}