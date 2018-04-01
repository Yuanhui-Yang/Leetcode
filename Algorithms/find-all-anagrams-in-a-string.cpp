// 438. Find All Anagrams in a String
// https://leetcode.com/problems/find-all-anagrams-in-a-string/

/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        array<int, 26> A, B;
        A.fill(0);
        B.fill(0);
        int sz1 = s.size(), sz2 = p.size(), i = 0, j = 0, k = 0, cnt = 0;
        vector<int> result;
        for (const auto & ch : p) {
            int id = ch - 'a';
            if (A[id] == 0) {
                ++k;
            }
            ++A[id];
        }
        while (j < sz1) {
            int id = s[j] - 'a';
            ++B[id];
            if (B[id] == A[id]) {
                ++cnt;
            }
            ++j;
            while (cnt == k) {
                if (j - i == sz2) {
                    result.push_back(i);
                }
                int id = s[i] - 'a';
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
