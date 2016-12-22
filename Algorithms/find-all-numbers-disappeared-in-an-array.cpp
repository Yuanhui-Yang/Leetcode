// 448. Find All Numbers Disappeared in an Array
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_set>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/66063/5-line-java-easy-understanding
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		const int nums_size = nums.size();
		vector<int> result;
		for (int i = 0; i < nums_size; i++) {
			int index = abs(nums[i]) - 1;
			if (nums[index] > 0) {
				nums[index] = -nums[index];
			}
		}
		for (int i = 0; i < nums_size; i++) {
			if (nums[i] > 0) {
				result.push_back(1 + i);
			}
		}
		return result;
	}
};
// END: https://discuss.leetcode.com/topic/66063/5-line-java-easy-understanding
// class Solution {
// public:
// 	vector<int> findDisappearedNumbers(vector<int>& nums) {
// 		const int nums_size = nums.size();
// 		unordered_set<int> hashset(begin(nums), end(nums));
// 		vector<int> result;
// 		for (int i = 1; i <= nums_size; i++) if (!hashset.count(i)) result.push_back(i);
// 		return result;
// 	}
// };
int main(void) {
	Solution solution;
	vector<int> nums, result;
	nums = { 4, 3, 2, 7, 8, 2, 3, 1 };
	result = solution.findDisappearedNumbers(nums);
	sort(begin(result), end(result));
	assert(vector<int>({ 5, 6 }) == result);
	nums = { 1, 1 };
	result = solution.findDisappearedNumbers(nums);
	sort(begin(result), end(result));
	assert(vector<int>({ 2 }) == result);
	cout << "\nPassed All\n";
	return 0;
}