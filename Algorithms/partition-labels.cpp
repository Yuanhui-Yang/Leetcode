763. Partition Labels
https://leetcode.com/problems/partition-labels/

A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        array<array<int, 2>, 26> A;
        A.fill({-1, -1});
        vector<int> result;
        int sz = S.size(), i, lower, upper;
        for (i = 0; i < sz; ++i) {
            int id = S[i] - 'a';
            if (A[id][0] < 0) {
                A[id][0] = i;
                A[id][1] = i;
            }
            else {
                A[id][1] = i;
            }
        }
        sort(A.begin(), A.end());
        i = 0;
        while (i < 26) {
            if (A[i][0] < 0) {
                ++i;
                continue;
            }
            lower = A[i][0];
            upper = A[i][1];
            ++i;
            while (i < 26 and A[i][0] <= upper) {
                upper = max(upper, A[i][1]);
                ++i;
            }
            result.push_back(upper + 1 - lower);
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    string S;
    vector<int> result;
    
    S = "ababcbacadefegdehijhklij";
    result = solution.partitionLabels(S);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';
    
    return 0;
}