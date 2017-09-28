// 525. Contiguous Array
// https://leetcode.com/problems/contiguous-array/

/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int result = 0, sz = nums.size(), i = 0, cnt = 0;
		vector<int> A(2 * sz + 1, -2);
		A[sz] = -1;
		for (i = 0; i < sz; ++i) {
			cnt += nums[i] == 1 ? 1 : -1;
			if (A[cnt + sz] >= -1) {
				result = max(result, i - A[cnt + sz]);
			}
			else {
				A[cnt + sz] = i;
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	int result;

	nums = {0, 0, 1, 0, 0, 0, 1, 1};
	result = solution.findMaxLength(nums);
	cout << result << '\n';
	
	return 0;
}