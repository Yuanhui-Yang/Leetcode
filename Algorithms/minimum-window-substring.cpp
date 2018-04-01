// 76. Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/

/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }
        array<int, 512> A, B;
        A.fill(0);
        B.fill(0);
        int sz = s.size(), i = 0, j = 0, k = 0, cnt = 0;
        for (const auto & ch : t) {
            int id = ch;
            if (A[id] == 0) {
                ++k;
            }
            ++A[id];
        }
        string result;
        while (j < sz) {
            int id = s[j];
            ++B[id];
            if (B[id] == A[id]) {
                ++cnt;
            }
            ++j;
            while (cnt == k) {
                if (result.empty() or j - i < result.size()) {
                    result = s.substr(i, j - i);
                }
                int id = s[i];
                if (B[id] == A[id]) {
                    --cnt;
                }
                --B[id];
                ++i;
            }
        }
        return result;
    }
};
