15. 3Sum
https://leetcode.com/problems/3sum/

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int sz = nums.size(), i = 0; i < sz; ++i) {
            if (i == 0 or nums[i - 1] != nums[i]) {
                vector<vector<int>> v = f1(nums, -nums[i], i);
                result.insert(result.end(), v.begin(), v.end());
            }
        }
        return result;
    }
private:
    vector<vector<int>> f1(vector<int>& nums, int target, int begin) {
        int end = nums.size();
        vector<vector<int>> result;
        int i = begin + 1, j = end - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == target) {
                result.push_back({nums[begin], nums[i], nums[j]});
                while (i + 1 < j and nums[i] == nums[i + 1]) {
                    ++i;
                }
                ++i;
                while (i < j - 1 and nums[j - 1] == nums[j]) {
                    --j;
                }
                --j;
            }
            else if (sum < target) {
                while (i + 1 < j and nums[i] == nums[i + 1]) {
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
    vector<int> nums;
    vector<vector<int>> result;

    nums = {-1, 0, 1, 2, -1, -4};
    result = solution.threeSum(nums);
    for (const auto & i : result) {
        for (const auto & j : i) {
            cout << j << '\t';
        }
        cout << '\n';
    }

    return 0;
}