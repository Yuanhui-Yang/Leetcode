// 340. Longest Substring with At Most K Distinct Characters
// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.
*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
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
            while (cnt > k) {
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
