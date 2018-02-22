215. Kth Largest Element in an Array
https://leetcode.com/problems/kth-largest-element-in-an-array/

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int sz = nums.size(), i = 0, j = sz;
        k = sz - k;
        while (i < j) {
            int id = partition(nums, i, j);
            if (id == k) {
                return nums[id];
            }
            else if (id < k) {
                i = id + 1;
            }
            else {
                j = id;
            }
        }
        return -1;
    }
private:
    int partition(vector<int>& nums, int begin, int end) {
        if (begin >= end) {
            return -1;
        }
        if (begin + 1 == end) {
            return begin;
        }
        int i = begin + 1, j = end - 1;
        while (i <= j) {
            if (nums[i] <= nums[begin]) {
                ++i;
            }
            else if (nums[j] >= nums[begin]) {
                --j;
            }
            else {
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[begin], nums[i - 1]);
        return i - 1;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums;
    int k, result;
    
    nums = {3, 2, 1, 5, 6, 4};
    k = 2;
    result = solution.findKthLargest(nums, k);
    cout << result << '\n';
    
    return 0;
}