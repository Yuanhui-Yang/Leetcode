805. Split Array With Same Average
https://leetcode.com/problems/split-array-with-same-average/

In a given integer array A, we must move every element of A to either list B or list C. (B and C initially start empty.)

Return true if and only if after such a move, it is possible that the average value of B is equal to the average value of C, and B and C are both non-empty.

Example :
Input: 
[1,2,3,4,5,6,7,8]
Output: true
Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have the average of 4.5.
Note:

The length of A will be in the range [1, 30].
A[i] will be in the range of [0, 10000].

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int sz = A.size();
        vector<unordered_set<int>> B(sz + 1);
        B[0].insert(0);
        for (int i = 0; i < sz; ++i) {
            int val = A[i];
            for (int j = i; j >= 0; --j) {
                for (const auto & k : B[j]) {
                    B[j + 1].insert(k + val);
                }   
            }
        }
        int total = *(B[sz].begin());
        for (int i = 1; i < sz; ++i) {
            for (const auto & j : B[i]) {
                if (j * sz == total * i) {
                    return true;
                }
            }
        }
        return false;
    }
};
