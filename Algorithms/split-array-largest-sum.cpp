410. Split Array Largest Sum
https://leetcode.com/problems/split-array-largest-sum/

Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

Note:
If n is the length of array, assume the following constraints are satisfied:

1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)
Examples:

Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sz = nums.size();
        vector<int> A = f1(nums), B(A);
        for (int i = 2; i <= m; ++i) {
            for (int j = sz; j >= i; --j) {
                B[j] = INT_MAX;
                for (int k = j - 1; k >= i - 1; --k) {
                    int sum = max(B[k], A[j] - A[k]);
                    B[j] = min(B[j], sum);
                }
            }
        }
        return B[sz];
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
};

int main(void) {
    Solution solution;
    vector<int> nums;
    int m, result;

    nums = {7,2,5,10,8};
    m = 2;
    result = solution.splitArray(nums, m);
    cout << result << '\n';

    return 0;
}
