// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<int, 512> A;
        A.fill(0);
        int sz = s.size(), i = 0, j = 0, cnt = 0, result = 0;
        while (j < sz) {
            int id = s[j];
            if (A[id] > 0) {
                ++cnt;
            }
            ++A[id];
            ++j;
            while (cnt > 0) {
                int id = s[i];
                --A[id];
                if (A[id] > 0) {
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
