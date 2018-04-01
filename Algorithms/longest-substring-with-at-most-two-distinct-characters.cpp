// 159. Longest Substring with At Most Two Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

/*
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.
*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        array<int, 512> A;
        A.fill(0);
        int sz = s.size(), i = 0, j = 0, cnt = 0, result = 0;
        while (j < sz) {
            int id = s[j];
            if (A[id] == 0) {
                ++cnt;
            }
            ++A[id];
            ++j;
            while (cnt > 2) {
                int id = s[i];
                --A[id];
                if (A[id] == 0) {
                    --cnt;
                }
                ++i;
            }
            if (result < j - i) {
                result = j - i;
            }
        }
        return result;
    }
};
