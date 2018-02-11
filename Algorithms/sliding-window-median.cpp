480. Sliding Window Median
https://leetcode.com/problems/sliding-window-median/

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Median
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
Therefore, return the median sliding window as [1,-1,-1,3,5,6].

Note: 
You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.

#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        int sz = nums.size(), i = 0;
        multiset<int> A;
        while (i < k and i < sz) {
            A.insert(nums[i]);
            ++i;
        }
        double median = f1(A);
        result.push_back(median);
        while (i < sz) {
            A.erase(A.find(nums[i - k]));
            A.insert(nums[i]);
            median = f1(A);
            result.push_back(median);
            ++i;
        }
        return result;
    }
private:
    double f1(multiset<int> & A) {
        int k = A.size();
        multiset<int>::iterator b = next(A.begin(), k / 2);
        if (k % 2) {
            return *b;
        }
        multiset<int>::iterator a = prev(b);
        return 0.5 * (*a) + 0.5 * (*b);
    }
};

int main(void) {
    Solution solution;
    vector<int> nums;
    int k;
    vector<double> result;

    nums = {1, 3, -1, -3, 5, 3, 6, 7};
    k = 3;
    result = solution.medianSlidingWindow(nums, k);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    return 0;
}