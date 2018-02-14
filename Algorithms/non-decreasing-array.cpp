665. Non-decreasing Array
https://leetcode.com/problems/non-decreasing-array/

Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.
Note: The n belongs to [1, 10,000].

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 2) {
            return true;
        }
        int i = 0;
        while (i + 1 < sz and nums[i] <= nums[i + 1]) {
            ++i;
        }
        if (i + 2 >= sz) {
            return true;
        }
        int j = sz - 1;
        while (j - 1 >= 0 and nums[j - 1] <= nums[j]) {
            --j;
        }
        if (j - i >= 2) {
            return false;
        }
        if (i == 0 or nums[i - 1] <= nums[j] or nums[i] <= nums[j + 1]) {
            return true;
        }
        return false;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums;
    bool result;
    
    nums = {4, 2, 3};
    result = solution.checkPossibility(nums);
    cout << boolalpha << result << '\n';

    nums = {4, 2, 1};
    result = solution.checkPossibility(nums);
    cout << boolalpha << result << '\n';
    
    return 0;
}