// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/

/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int sz1 = nums1.size(), sz2 = nums2.size(), i = 0, j = 0;
        vector<int> result;
        while (i < sz1 and j < sz2)
        {
            int a = nums1[i], b = nums2[j];
            if (a == b)
            {
                result.push_back(a);
                while (i < sz1 and nums1[i] == a)
                {
                    ++i;
                }
                while (j < sz2 and nums2[j] == b)
                {
                    ++j;
                }
            }
            else if (a < b)
            {
                while (i < sz1 and nums1[i] == a)
                {
                    ++i;
                }
            }
            else
            {
                while (j < sz2 and nums2[j] == b)
                {
                    ++j;
                }
            }
        }
        return result;
    }
};
