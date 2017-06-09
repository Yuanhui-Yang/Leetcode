// 485. Max Consecutive Ones
// https://leetcode.com/problems/max-consecutive-ones/

/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int result = 0, len = 0;
		for (const auto &i : nums) {
			if (i == 1) {
				result = result < ++len ? len : result;
			}
			else {
				len = 0;
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	int answer, result;

	nums = {1, 1, 0, 1, 1, 1};
	answer = 3;
	result = solution.findMaxConsecutiveOnes(nums);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}