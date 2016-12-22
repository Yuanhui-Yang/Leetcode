// 442. Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/64735/java-simple-solution
class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		const int nums_size = nums.size();
		vector<int> result;
		for (int i = 0; i < nums_size; i++) {
			int index = abs(nums[i]) - 1;
			if (nums[index] > 0) {
				nums[index] = -nums[index];
			}
			else {
				result.push_back(index + 1);
			}
		}
		return result;
	}
};
// END: https://discuss.leetcode.com/topic/64735/java-simple-solution
// class Solution {
// public:
// 	vector<int> findDuplicates(vector<int>& nums) {
// 		sort(begin(nums), end(nums));
// 		vector<int> result;
// 		for (size_t i = 0; i + 1 < nums.size(); i++)
// 			if (nums[i] == nums[i + 1])
// 				result.push_back(nums[i++]);
// 		return result;
// 	}
// };
int main(void) {
	Solution solution;
	vector<int> nums, result;
	nums = {4, 3, 2, 7, 8, 2, 3, 1};
	result = solution.findDuplicates(nums);
	sort(begin(result), end(result));
	assert(vector<int>({2, 3}) == result);
	cout << "\nPassed All\n";
	return 0;
}