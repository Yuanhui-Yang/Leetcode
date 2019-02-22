33. Search in Rotated Sorted Array
https://leetcode.com/problems/search-in-rotated-sorted-array/

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size(), i = 0, j = sz;
        while (i < j)
        {
            int k = i + (j - i) / 2;
            if (nums[0] <= nums[k])
            {
                if (nums[k] < target)
                {
                    i = k + 1;
                }
                else if (nums[0] <= target)
                {
                    j = k;
                }
                else
                {
                    i = k + 1;
                }
            }
            else
            {
                if (nums[0] <= target)
                {
                    j = k;
                }
                else if (nums[k] < target)
                {
                    i = k + 1;
                }
                else
                {
                    j = k;
                }
            }
        }
        return i < sz and nums[i] == target ? i : -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size(), i = 0, j = sz;
        while (i < j) {
            int k = i + (j - i) / 2;
            if (target < nums[0]) {
                if (nums[0] <= nums[k]) {
                    i = k + 1;
                }
                else if (nums[k] < target) {
                    i = k + 1;
                }
                else {
                    j = k;
                }
            }
            else {
                if (nums[k] < nums[0]) {
                    j = k;
                }
                else if (nums[k] < target) {
                    i = k + 1;
                }
                else {
                    j = k;
                }
            }
        }
        return i == sz or nums[i] != target ? -1 : i;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums;
    int target, result;
    
    nums = {4, 5, 6, 7, 0, 1, 2};
    target = 0;
    result = solution.search(nums, target);
    cout << result << '\n';
    
    return 0;
}
