268. Missing Number
https://leetcode.com/problems/missing-number/

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1

Input: [3,0,1]
Output: 2
Example 2

Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sz = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        return sz * (sz + 1) / 2 - sum;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums;
    int result;

    nums = {3, 0, 1};
    result = solution.missingNumber(nums);
    cout << result << '\n';

    nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    result = solution.missingNumber(nums);
    cout << result << '\n';

    return 0;
}
