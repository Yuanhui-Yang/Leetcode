// 1. Two Sum
// https://leetcode.com/problems/two-sum/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>
using namespace std;
// BEGIN: https://leetcode.com/articles/two-sum/
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		const int nums_size = nums.size();
		if (nums_size < 2) return {-1, -1};
		unordered_map<int, int> hash_map;
		for (int i = 0; i < nums_size; i++) {
			if (hash_map.count(target - nums[i])) {
				return {hash_map[target - nums[i]], i};
			}
			hash_map[nums[i]] = i;
		}
		return {-1, -1};
	}
};
// END: https://leetcode.com/articles/two-sum/
int main(void) {
	Solution solution;
	vector<int> nums;
	nums = {2, 7, 11, 15};
	assert(vector<int>({0, 1}) == solution.twoSum(nums, 9));
	nums = {3, 2, 4};
	assert(vector<int>({1, 2}) == solution.twoSum(nums, 6));
	cout << "\nPassed All\n";
	return 0;
}