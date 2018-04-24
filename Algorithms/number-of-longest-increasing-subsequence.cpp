// 673. Number of Longest Increasing Subsequence
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

/*
Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) {
            return 0;
        }
        int result = 1, max_len = 1;
        vector<array<int, 2>> A(sz);
        A[0].fill(1);
        for (int i = 1; i < sz; ++i) {
            int len = 1, cnt = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (len < A[j][0] + 1) {
                        len = A[j][0] + 1;
                        cnt = A[j][1];
                    }
                    else if (A[j][0] + 1 == len) {
                        cnt += A[j][1];
                    }
                }
            }
            A[i][0] = len;
            A[i][1] = cnt;
            if (max_len < len) {
                max_len = len;
                result = cnt;
            }
            else if (max_len == len) {
                result += cnt;
            }
        }
        return result;
    }
};

int main(void) {
	Solution solution;
	vector<int> nums;
	int result;
	
	nums = {1, 3, 5, 4, 7};
	result = solution.findNumberOfLIS(nums);
	cout << result << '\n';

	nums = {2, 2, 2, 2, 2};
	result = solution.findNumberOfLIS(nums);
	cout << result << '\n';

	nums = {1, 2, 4, 3, 5, 4, 7, 2};
	result = solution.findNumberOfLIS(nums);
	cout << result << '\n';
	
	return 0;
}
