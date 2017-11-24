// 727. Minimum Window Subsequence
// https://leetcode.com/problems/minimum-window-subsequence/

/*
Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:
Input: 
S = "abcdebdde", T = "bde"
Output: "bcde"
Explanation: 
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of T in the window must occur in order.
Note:

All the strings in the input will only contain lowercase letters.
The length of S will be in the range [1, 20000].
The length of T will be in the range [1, 100].
*/

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        int sz1 = S.size(), sz2 = T.size(), i, j;
        array<vector<int>, 26> A;
        array<int, 2> B, C;
        B.fill(0);
        i = 0;
        while (i < sz1) {
            j = S[i] - 'a';
            A[j].push_back(i);
            ++i;
        }
        i = 0;
        j = T[i] - 'a';
        if (A[j].empty()) {
            return "";
        }
        for (const auto & k : A[j]) {
            C = f1(A, T, k);
            if (C[0] < C[1] and (B[0] == B[1] or C[1] - C[0] < B[1] - B[0])) {
                B = C;
            }
        }
        return S.substr(B[0], B[1] - B[0]);
    }
private:
    array<int, 2> f1(array<vector<int>, 26> & A, string & T, int k) {
        int sz = T.size(), i = 1, j;
        vector<int>::iterator a, b;
        array<int, 2> result;
        result.fill(k);
        while (i < sz) {
            j = T[i] - 'a';
            vector<int> & B = A[j];
            b = B.end();
            a = upper_bound(B.begin(), B.end(), result[1]);
            if (a == b) {
                return {0, 0};
            }
            result[1] = *a;
            ++i;
        }
        ++result[1];
        return result;
    }
};

int main(void) {
    Solution solution;
    string S, T, result;

    S = "abcdebdde";
    T = "bde";
    result = solution.minWindow(S, T);
    cout << result << '\n';

    S = "cnhczmccqouqadqtmjjzl";
    T = "mm";
    result = solution.minWindow(S, T);
    cout << result << '\n';

    return 0;
}