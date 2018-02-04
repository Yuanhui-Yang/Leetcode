321. Create Maximum Number
https://leetcode.com/problems/create-maximum-number/

Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.

Example 1:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
return [9, 8, 6, 5, 3]

Example 2:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
return [6, 7, 6, 0, 4]

Example 3:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
return [9, 8, 9]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result;
        int sz1 = nums1.size(), sz2 = nums2.size();
        for (int i = 0; i <= sz1; ++i) {
            if (i <= k) {
                int j = k - i;
                if (j <= sz2) {
                    vector<int> a = f1(nums1, i), b = f1(nums2, j), c = f3(a, b);
                    if (result.empty() or result < c) {
                        result = c;
                    }   
                }
            }
        }
        return result;
    }
private:
    vector<int> f1(vector<int> & A, int k) {
        int sz = A.size();
        if (sz < k) {
            return {};
        }
        if (sz == k) {
            return A;
        }
        vector<int> result;
        int begin = 0, end = sz;
        while (k-- > 0) {
            int id = f2(A, begin, end - k);
            if (id < 0) {
                return {};
            }
            result.push_back(A[id]);
            begin = id + 1;
        }
        return result;
    }
    int f2(vector<int> & A, int begin, int end) {
        int result = -1;
        for (int i = begin; i < end; ++i) {
            if (result < 0) {
                result = i;
            }
            else if (A[result] < A[i]) {
                result = i;
            }
        }
        return result;
    }
    vector<int> f3(vector<int> & A, vector<int> & B) {
        vector<int> result;
        int sz1 = A.size(), sz2 = B.size(), i = 0, j = 0;
        while (i < sz1 or j < sz2) {
            if (f4(A, i, B, j)) {
                result.push_back(A[i]);
                ++i;
            }
            else {
                result.push_back(B[j]);
                ++j;
            }
        }
        return result;
    }
    bool f4(vector<int> & A, int begin1, vector<int> & B, int begin2) {
        int end1 = A.size(), end2 = B.size();
        while (begin1 < end1 and begin2 < end2 and A[begin1] == B[begin2]) {
            ++begin1;
            ++begin2;
        }
        if (begin2 == end2) {
            return true;
        }
        if (begin1 == end1) {
            return false;
        }
        return A[begin1] > B[begin2];
    }
};

int main(void) {
    Solution solution;
    vector<int> nums1, nums2, result;
    int k;
    
    nums1 = {3, 4, 6, 5};
    nums2 = {9, 1, 2, 5, 8, 3};
    k = 5;
    result = solution.maxNumber(nums1, nums2, k);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    nums1 = {6, 7};
    nums2 = {6, 0, 4};
    k = 5;
    result = solution.maxNumber(nums1, nums2, k);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    nums1 = {3, 9};
    nums2 = {8, 9};
    k = 3;
    result = solution.maxNumber(nums1, nums2, k);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';
    
    return 0;
}