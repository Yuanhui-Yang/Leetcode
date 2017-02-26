// 523. Continuous Subarray Sum
// https://leetcode.com/problems/continuous-subarray-sum/
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		if (nums.size() < 2) {
			return false;
		}
		for (size_t i = 1; i < nums.size(); i++) {
			if (nums.at(i) == 0 && nums.at(i - 1) == 0) {
				return true;
			}
		}
		if (k == 0) {
			return false;
		}
		k = abs(k);
		if (k == 1) {
			return true;
		}
		set<int> tree_set;
		tree_set.insert(0);
		int cnt = 0;
		for (const auto &num : nums) {
			const int up = num + *prev(end(tree_set));
			const int low = num;
			for (int i = 1; k && i <= (up - low) / k + 1; i++) {
				const set<int>::iterator it = tree_set.lower_bound(up - k * i);
				if (cnt >= 1 && it != end(tree_set) && *it == (up - k * i)) {
					return true;
				}
			}
			tree_set.insert(up);
			cnt++;
		} 
		return false;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums;
	int k = 0;
	bool result = false;
	bool answer = false;

	nums = {1, 1000000000};
	k = 1;
	answer = true;
	result = solution.checkSubarraySum(nums, k);
	assert(answer == result);

	nums = {5, 2, 4};
	k = 5;
	answer = false;
	result = solution.checkSubarraySum(nums, k);
	assert(answer == result);

	nums = {0, 0};
	k = -1;
	answer = true;
	result = solution.checkSubarraySum(nums, k);
	assert(answer == result);

	nums = {0, 1, 0};
	k = 0;
	answer = false;
	result = solution.checkSubarraySum(nums, k);
	assert(answer == result);

	nums = {23, 2, 4, 6, 7};
	k = -6;
	answer = true;
	result = solution.checkSubarraySum(nums, k);
	assert(answer == result);

	nums = {0};
	k = 0;
	answer = false;
	result = solution.checkSubarraySum(nums, k);
	assert(answer == result);

	nums = {0, 0};
	k = 0;
	answer = true;
	result = solution.checkSubarraySum(nums, k);
	assert(answer == result);

	nums = {23, 2, 6, 4, 7};
	k = 0;
	answer = false;
	result = solution.checkSubarraySum(nums, k);
	assert(answer == result);

	nums = {23, 2, 4, 6, 7};
	k = 6;
	answer = true;
	result = solution.checkSubarraySum(nums, k);
	assert(answer == result);

	nums = {23, 2, 6, 4, 7};
	k = 6;
	answer = true;
	result = solution.checkSubarraySum(nums, k);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}