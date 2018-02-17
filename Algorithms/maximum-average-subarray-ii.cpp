644. Maximum Average Subarray II
https://leetcode.com/problems/maximum-average-subarray-ii/

Given an array consisting of n integers, find the contiguous subarray whose length is greater than or equal to k that has the maximum average value. And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation:
when length is 5, maximum average value is 10.8,
when length is 6, maximum average value is 9.16667.
Thus return 12.75.
Note:
1 <= k <= n <= 10,000.
Elements of the given array will be in range [-10,000, 10,000].
The answer with the calculation error less than 10-5 will be accepted.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        pair<vector<int>::iterator, vector<int>::iterator> p = minmax_element(nums.begin(), nums.end());
        double a = *(p.first), b = *(p.second);
        while (b - a >= 1e-5) {
            double c = (a + b) / 2;
            if (f1(nums, k, c)) {
                a = c;
            }
            else {
                b = c;
            }
        }
        return a;
    }
private:
    bool f1(vector<int>& nums, int k, double c) {
        double curr_sum = 0, min_prev_sum = 0, prev_sum = 0;
        int sz = nums.size(), i = 0;
        while (i < k) {
            double curr = nums[i] - c;
            curr_sum += curr;
            ++i;
        }
        if (curr_sum >= 0) {
            return true;
        }
        while (i < sz) {
            double prev = nums[i - k] - c, curr = nums[i] - c;
            prev_sum += prev;
            curr_sum += curr;
            min_prev_sum = min(min_prev_sum, prev_sum);
            if (curr_sum >= min_prev_sum) {
                return true;
            }
            ++i;
        }
        return false;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums;
    int k;
    double result;
    
    nums = {1, 12, -5, -6, 50, 3};
    k = 4;
    result = solution.findMaxAverage(nums, k);
    cout << result << '\n';
    
    return 0;
}