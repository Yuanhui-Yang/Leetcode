// 462. Minimum Moves to Equal Array Elements II
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
using namespace std;
class Solution {
public:
	int minMoves2(vector<int>& nums) {
		if (nums.size() < 2) return 0;
		sort(begin(nums), end(nums));
		const int n = nums.size();
		int mid = nums[n >> 1];
		int result = 0;
		for (const auto &i : nums) result += abs(i - mid);
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<int> nums;
	cout << solution.minMoves2(nums) << "\tPassed\n";
	nums = {1,2,3};
	cout << solution.minMoves2(nums) << "\tPassed\n";
	nums = {1,0,0,8,6};
	cout << solution.minMoves2(nums) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}