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
        int sz = nums.size(), a = nums[0], b = nums[0];
        k = sz - k + 1;
        for (const auto & i : nums) {
            a = min(a, i);
            b = max(b, i);
        }
        ++b;
        while (a < b) {
            int c = a + (b - a) / 2;
            if (f1(nums, c, k)) {
                a = c + 1;
            }
            else {
                b = c;
            }
        }
        return a;
    }
private:
    bool f1(vector<int>& nums, int c, int k) {
        return f2(nums, c) < k;
    }
    int f2(vector<int>& nums, int c) {  
        int result = 0;
        for (const auto & i : nums) {
            if (i <= c) {
                ++result;
            }
        }
        return result;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int sz = nums.size(), i = 0, j = sz;
        k = sz - k;
        while (i < j) {
            int l = partition(nums, i, j);
            if (k == l) {
                return nums[l];
            }
            else if (l < k) {
                i = l + 1;
            }
            else {
                j = l;
            }
        }
        return -1;
    }
private:
    int partition(vector<int> & nums, int begin, int end) {
        if (begin >= end) {
            return -1;
        }
        if (begin + 1 >= end) {
            return begin;
        }
        int pivot = nums[begin], i = begin + 1, j = end - 1;
        while (i <= j) {
            if (nums[i] <= pivot) {
                ++i;
            }
            else if (nums[j] >= pivot) {
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