// 416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/

/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sz = nums.size(), i = 0, j = 0, target = accumulate(begin(nums), end(nums), 0);
		if (target % 2) {
			return false;
		}
		target /= 2;
		sort(begin(nums), end(nums));
		vector<vector<bool>> A(target + 1, vector<bool>(sz + 1, false));
		for (i = 0; i <= sz; ++i) {
			A[0][i] = true;
		}
		for (i = 1; i <= target; ++i) {
			for (j = sz - 1; j >= 0; --j) {
				A[i][j] = A[i][j + 1];
				if (i >= nums[j]) {
					A[i][j] = A[i][j] or A[i - nums[j]][j + 1];
				}
			}
		}
		return A[target][0];
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	bool result;

	nums = {1, 5, 11, 5};
	result = solution.canPartition(nums);
	cout << boolalpha << result << '\n';

	nums = {1, 2, 3, 5};
	result = solution.canPartition(nums);
	cout << boolalpha << result << '\n';

	nums = {1, 2, 3, 4, 5, 6, 7};
	result = solution.canPartition(nums);
	cout << boolalpha << result << '\n';
	
	return 0;
}