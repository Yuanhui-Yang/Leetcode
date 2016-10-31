// 442. Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		sort(begin(nums), end(nums));
		vector<int> result;
		for (size_t i = 0; i + 1 < nums.size(); i++)
			if (nums[i] == nums[i + 1])
				result.push_back(nums[i++]);
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
	for (const auto &i : solution.findDuplicates(nums)) cout << i << '\t';
	cout << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}