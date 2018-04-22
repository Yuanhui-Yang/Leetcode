801. Minimum Swaps To Make Sequences Increasing
https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

We have two integer sequences A and B of the same non-zero length.

We are allowed to swap elements A[i] and B[i].  Note that both elements are in the same index position in their respective sequences.

At the end of some number of swaps, A and B are both strictly increasing.  (A sequence is strictly increasing if and only if A[0] < A[1] < A[2] < ... < A[A.length - 1].)

Given A and B, return the minimum number of swaps to make both sequences strictly increasing.  It is guaranteed that the given input always makes it possible.

Example:
Input: A = [1,3,5,4], B = [1,2,3,7]
Output: 1
Explanation: 
Swap A[3] and B[3].  Then the sequences are:
A = [1, 3, 5, 7] and B = [1, 2, 3, 4]
which are both strictly increasing.
Note:

A, B are arrays with the same length, and that length will be in the range [1, 1000].
A[i], B[i] are integer values in the range [0, 2000].

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int sz = A.size(), swap = 1, keep = 0;
        for (int i = 1; i < sz; ++i) {
            int nswap = INT_MAX, nkeep = INT_MAX;
            if (A[i - 1] < A[i] and B[i - 1] < B[i]) {
                nswap = min(nswap, swap + 1);
                nkeep = min(nkeep, keep);
            }
            if (A[i - 1] < B[i] and B[i - 1] < A[i]) {
                nswap = min(nswap, keep + 1);
                nkeep = min(nkeep, swap);
            }
            swap = nswap;
            keep = nkeep;
        }
        return min(swap, keep);
    }
};

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int sz = A.size();
        vector<int> Swap(sz, INT_MAX), Keep(sz, INT_MAX);
        Swap[0] = 1;
        Keep[0] = 0;
        for (int i = 1; i < sz; ++i) {
            if (A[i - 1] < A[i] and B[i - 1] < B[i]) {
                Swap[i] = min(Swap[i], Swap[i - 1] + 1);
                Keep[i] = min(Keep[i], Keep[i - 1]);
            }
            if (A[i - 1] < B[i] and B[i - 1] < A[i]) {
                Swap[i] = min(Swap[i], Keep[i - 1] + 1);
                Keep[i] = min(Keep[i], Swap[i - 1]);
            }
        }
        return min(Swap.back(), Keep.back());
    }
};

int main(void) {
    Solution solution;
    vector<int> A, B;
    int result;

    A = {1, 3, 5, 4};
    B = {1, 2, 3, 7};
    result = solution.minSwap(A, B);
    cout << result << '\n';

    return 0;
}
