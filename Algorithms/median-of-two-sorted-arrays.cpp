4. Median of Two Sorted Arrays
https://leetcode.com/problems/median-of-two-sorted-arrays/

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size(), sz = sz1 + sz2;
        if (sz % 2) {
            return f1(nums1, nums2, sz / 2 + 1);
        }
        else {
            return 0.5 * f1(nums1, nums2, sz / 2) + 0.5 * f1(nums1, nums2, sz / 2 + 1);
        }
    }
private:
    int f1(vector<int>& nums1, vector<int>& nums2, int k) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        if (sz1 == 0) {
            return nums2[k - 1];
        }
        if (sz2 == 0) {
            return nums1[k - 1];
        }
        int left = min(nums1.front(), nums2.front());
        int right = 1 + max(nums1.back(), nums2.back());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (f2(nums1, nums2, mid, k)) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
    bool f2(vector<int>& nums1, vector<int>& nums2, int val, int k) {
        int cnt = 0;
        cnt += distance(nums1.begin(), upper_bound(nums1.begin(), nums1.end(), val));
        cnt += distance(nums2.begin(), upper_bound(nums2.begin(), nums2.end(), val));
        return cnt < k;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums1, nums2;
    double result;
    
    nums1 = {1, 3};
    nums2 = {2};
    result = solution.findMedianSortedArrays(nums1, nums2);
    cout << result << '\n';
    
    nums1 = {1, 2};
    nums2 = {3, 4};
    result = solution.findMedianSortedArrays(nums1, nums2);
    cout << result << '\n';
    
    return 0;
}
