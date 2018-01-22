1. Two Sum
https://leetcode.com/problems/two-sum/

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> A;
        int sz = nums.size(), i, x, y;
        for (i = 0; i < sz; ++i) {
            x = nums[i];
            y = target - x;
            if (A.count(y)) {
                return {A[y], i};
            }
            A[x] = i;
        }
        return {};
    }
};

int main(void) {
    Solution solution;
    vector<int> nums, result;
    int target;

    nums = {2, 7, 11, 15};
    target = 9;
    result = solution.twoSum(nums, target);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    
    return 0;
}