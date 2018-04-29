377. Combination Sum IV
https://leetcode.com/problems/combination-sum-iv/

Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> A(target + 1, 0);
        A[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (const auto & j : nums) {
                if (j <= i) {
                    A[i] += A[i - j];
                }
            }
        }
        return A[target];
    }
};

int main(void) {
    Solution solution;
    vector<int> nums;
    int target, result;

    nums = {1, 2, 3};
    target = 4;
    result = solution.combinationSum4(nums, target);
    cout << result << '\n';

    return 0;
}
