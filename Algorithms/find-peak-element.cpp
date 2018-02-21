162. Find Peak Element
https://leetcode.com/problems/find-peak-element/

A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) {
            return -1;
        }
        if (sz == 1) {
            return 0;
        }
        if (nums[0] > nums[1]) {
            return 0;
        }
        if (nums[sz - 2] < nums[sz - 1]) {
            return sz - 1;
        }
        int i = 1, j = sz - 1;
        while (i < j) {
            int k = i + (j - i) / 2;
            if (nums[k - 1] < nums[k]) {
                if (nums[k] < nums[k + 1]) {
                    i = k + 1;
                }
                else {
                    return k;
                }
            }
            else {
                j = k;
            }
        }
        return i;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums;
    int result;
    
    nums = {1, 2, 3, 1};
    result = solution.findPeakElement(nums);
    cout << result << '\n';
    
    return 0;
}