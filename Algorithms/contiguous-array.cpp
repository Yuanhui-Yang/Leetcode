525. Contiguous Array
https://leetcode.com/problems/contiguous-array/

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

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> A;
        int result = 0;
        A[0] = -1;
        for (int sz = nums.size(), sum = 0, i = 0; i < sz; ++i) {
            if (nums[i] == 0) {
                --sum;
            }
            else {
                ++sum;
            }
            if (A.count(sum)) {
                result = max(result, i - A[sum]);
            }
            else {
                A[sum] = i;
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums;
    int result;

    nums = {0, 1};
    result = solution.findMaxLength(nums);
    cout << result << '\n';

    nums = {0, 1, 0};
    result = solution.findMaxLength(nums);
    cout << result << '\n';

    return 0;
}
