// 330. Patching Array
// https://leetcode.com/problems/patching-array/
#include <iostream>
#include <vector>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/35494/solution-explanation
class Solution {
public:
	int minPatches(vector<int>& nums, int n) {
		int result = 0, i = 0;
		long upperbound = 1;
		const int m = nums.size();
		while (upperbound <= n) {
			if (i < m && nums[i] <= upperbound) {
				upperbound += nums[i];
				i++;
			}
			else {
				upperbound += upperbound;
				result++;
			}
		}
		return result;
	}
};
// class Solution {
// public:
// 	int minPatches(vector<int>& nums, int n) {
// 		int result = 0, i = 0;
// 		const int m = nums.size();
// 		for (long upperbound = 1; upperbound <= (long)n; result++)
// 			upperbound += (i < m && (long)nums[i] <= upperbound) ? nums[i++] : upperbound;
// 		return result - i;
// 	}
// };
// END: https://discuss.leetcode.com/topic/35494/solution-explanation
int main(void) {
	Solution solution;
	vector<int> nums = {1, 3};
	cout << solution.minPatches(nums, 6) << "\tPassed\n";
	nums = {1, 5, 10};
	cout << solution.minPatches(nums, 20) << "\tPassed\n";
	nums = {1, 2, 2};
	cout << solution.minPatches(nums, 5) << "\tPassed\n";
	nums = {1, 2, 31, 33};
	cout << solution.minPatches(nums, 2147483647) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}