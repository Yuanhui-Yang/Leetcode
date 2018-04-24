689. Maximum Sum of 3 Non-Overlapping Subarrays
https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/

In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

Example:
Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
Note:
nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> cumsums, left(sz, -1), right(sz, -1), result;
        cumsums.push_back(0);
        for (int i = 0; i < sz; ++i) {
            cumsums.push_back(cumsums.back() + nums[i]);
        }
        for (int i = k - 1; i < sz; ++i) {
            if (i == k - 1) {
                left[i] = 0;
            }
            else if (cumsums[left[i - 1] + k] - cumsums[left[i - 1]] < cumsums[i + 1] - cumsums[i + 1 - k]) {
                left[i] = i - k + 1;
            }
            else {
                left[i] = left[i - 1];
            }
        }
        for (int i = sz - k; i >= 0; --i) {
            if (i == sz - k) {
                right[i] = sz - k;
            }
            else if (cumsums[right[i + 1] + k] - cumsums[right[i + 1]] < cumsums[i + k] - cumsums[i]) {
                right[i] = i;
            }
            else {
                right[i] = right[i + 1];
            }
        }
        for (int i = k, max_sum = 0; i + 2 * k <= sz; ++i) {
            int center = cumsums[i + k] - cumsums[i];
            int sum = cumsums[left[i - 1] + k] - cumsums[left[i - 1]];
            sum += center;
            sum += cumsums[right[i + k] + k] - cumsums[right[i + k]];
            if (result.empty() or max_sum < sum) {
                max_sum = sum;
                result = {left[i - 1], i, right[i + k]};
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums, result;
    int k;
    
    nums = {1, 2, 1, 2, 6, 7, 5, 1};
    k = 2;
    result = solution.maxSumOfThreeSubarrays(nums, k);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';
    
    return 0;
}
