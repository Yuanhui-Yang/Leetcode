747. Largest Number At Least Twice of Others
https://leetcode.com/problems/largest-number-at-least-twice-of-others/

In a given integer array nums, there is always exactly one largest element.

Find whether the largest element in the array is at least twice as much as every other number in the array.

If it is, return the index of the largest element, otherwise return -1.

Example 1:

Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
 

Example 2:

Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
 

Note:

nums will have a length in the range [1, 50].
Every nums[i] will be an integer in the range [0, 99].

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int sz = nums.size(), x = -1, y = -1;
        if (sz == 0) {
            return -1;
        }
        if (sz == 1) {
            return 0;
        }
        for (int i = 0; i < sz; ++i) {
            if (x < 0) {
                x = i;
            }
            else if (y < 0) {
                if (nums[x] < nums[i]) {
                    y = x;
                    x = i;
                }
                else {
                    y = i;
                }
            }
            else {
                if (nums[x] < nums[i]) {
                    y = x;
                    x = i;
                }
                else if (nums[y] < nums[i]) {
                    y = i;
                }
            }
        }
        return 2 * nums[y] <= nums[x] ? x : -1;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums;
    int result;
    
    nums = {3, 6, 1, 0};
    result = solution.dominantIndex(nums);
    cout << result << '\n';
    
    nums = {1, 2, 3, 4};
    result = solution.dominantIndex(nums);
    cout << result << '\n';
    
    return 0;
}