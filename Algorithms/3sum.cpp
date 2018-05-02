15. 3Sum
https://leetcode.com/problems/3sum/

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

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
        for (int sz = nums.size(), i = 0; i + 2 < sz; ++i) {
            if (i == 0 or nums[i - 1] != nums[i]) {
                int j = i + 1, k = sz - 1;
                while (j < k) {
                    if (j > i + 1 and nums[j - 1] == nums[j]) {
                        ++j;
                    }
                    else if (k < sz - 1 and nums[k + 1] == nums[k]) {
                        --k;
                    }
                    else {
                        int sum = nums[i] + nums[j] + nums[k];
                        if (sum == 0) {
                            result.push_back({nums[i], nums[j], nums[k]});
                            ++j;
                            --k;
                        }
                        else if (sum < 0) {
                            ++j;
                        }
                        else {
                            --k;
                        }
                    }
                }
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
