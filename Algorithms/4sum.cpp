18. 4Sum
https://leetcode.com/problems/4sum/

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int sz = nums.size(), i = 0; i < sz; ++i) {
            if (i == 0 or nums[i - 1] != nums[i]) {
                for (int j = i + 1; j < sz; ++j) {
                    if (j == i + 1 or nums[j - 1] != nums[j]) {
                        vector<vector<int>> v = f1(nums, target - nums[i] - nums[j], j + 1);
                        for (const auto & x : v) {
                            vector<int> w;
                            w.push_back(nums[i]);
                            w.push_back(nums[j]);
                            for (const auto & y : x) {
                                w.push_back(nums[y]);
                            }
                            result.push_back(w);
                        }
                    }
                }
            }
        }
        return result;
    }
private:
    vector<vector<int>> f1(vector<int>& nums, int target, int begin) {
        int end = nums.size(), i = begin, j = end - 1;
        vector<vector<int>> result;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == target) {
                result.push_back({i, j});
                while (i + 1 < j and nums[i + 1] == nums[i]) {
                    ++i;
                }
                ++i;
                while (i < j - 1 and nums[j - 1] == nums[j]) {
                    --j;
                }
                --j;
            }
            else if (sum < target) {
                while (i + 1 < j and nums[i + 1] == nums[i]) {
                    ++i;
                }
                ++i;
            }
            else {
                while (i < j - 1 and nums[j - 1] == nums[j]) {
                    --j;
                }
                --j;
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    int target;
    vector<int> nums;
    vector<vector<int>> result;

    target = 0;
    nums = {0, 0, 0, 0};
    result = solution.fourSum(nums, target);
    for (const auto & i : result) {
        for (const auto & j : i) {
            cout << j << '\t';
        }
        cout << '\n';
    }
    cout << '\n';

    target = 0;
    nums = {-3, -2, -1, 0, 0, 1, 2, 3};
    result = solution.fourSum(nums, target);
    for (const auto & i : result) {
        for (const auto & j : i) {
            cout << j << '\t';
        }
        cout << '\n';
    }
    cout << '\n';

    target = 0;
    nums = {1, 0, -1, 0, -2, 2};
    result = solution.fourSum(nums, target);
    for (const auto & i : result) {
        for (const auto & j : i) {
            cout << j << '\t';
        }
        cout << '\n';
    }
    cout << '\n';

    return 0;
}