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
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int sz = nums.size(), max_sum = INT_MIN;
    vector<int> A = f1(nums), B = f2(A, sz, k), C = f3(A, sz, k), result;
    for (int i = k; i <= sz - 2 * k; ++i) {
      int curr_sum = 0;
      curr_sum += A[B[i] + k] - A[B[i]];
      curr_sum += A[i + k] - A[i];
      curr_sum += A[C[i + k] + k] - A[C[i + k]];
      if (curr_sum > max_sum) {
        max_sum = curr_sum;
        result = {B[i], i, C[i + k]};
      }
    }
    return result;
  }
private:
  vector<int> f1(vector<int>& nums) {
    vector<int> result;
    result.push_back(0);
    for (const auto & i : nums) {
      result.push_back(result.back() + i);
    }
    return result;
  }
  vector<int> f2(vector<int>& A, int sz, int k) {
    vector<int> result(sz + 1, 0);
    result[k] = 0;
    for (int i = k + 1, max_sum = A[k] - A[0]; i <= sz; ++i) {
      int curr_sum = A[i] - A[i - k];
      if (max_sum < curr_sum) {
        max_sum = curr_sum;
        result[i] = i - k;
      }
      else {
        result[i] = result[i - 1];
      }
    }
    return result;
  }
  vector<int> f3(vector<int>& A, int sz, int k) {
    vector<int> result(sz + 1, 0);
    int max_sum = A[sz] - A[sz - k];
    result[sz - k] = sz - k;
    for (int i = sz - k - 1; i >= 0; --i) {
      int curr_sum = A[i + k] - A[i];
      if (max_sum < curr_sum) {
        max_sum = curr_sum;
        result[i] = i;
      }
      else {
        result[i] = result[i + 1];
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