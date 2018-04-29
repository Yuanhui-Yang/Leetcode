283. Move Zeroes
https://leetcode.com/problems/move-zeroes/

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int sz = nums.size(), i = 0; i < sz; ++i) {
            if (nums[i]) {
                int j = i;
                while (j >= 1 and !nums[j - 1]) {
                    swap(nums[j - 1], nums[j]);
                    --j;
                }
            }
        }
    }
};

int main(void) {
    Solution solution;
    vector<int> nums;
    
    nums = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums);
    for (const auto & i : nums) {
        cout << i << '\t';
    }
    cout << '\n';
    
    return 0;
}
