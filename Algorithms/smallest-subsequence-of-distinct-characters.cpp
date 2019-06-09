1086. Smallest Subsequence of Distinct Characters
https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

Return the lexicographically smallest subsequence of text that contains all the distinct characters of text exactly once.

 

Example 1:

Input: "cdadabcc"
Output: "adbc"
Example 2:

Input: "abcd"
Output: "abcd"
Example 3:

Input: "ecbacba"
Output: "eacb"
Example 4:

Input: "leetcode"
Output: "letcod"
 

Note:

1 <= text.length <= 1000
text consists of lowercase English letters.

class Solution {
public:
    string smallestSubsequence(string text) {
        array<int, 26> A;
        A.fill(0);
        for (const auto & i : text)
        {
            int offset = i - 'a';
            ++A[offset];
        }
        string result;
        for (const auto & i : text)
        {
            if (result.find(i) == string::npos)
            {
                while (!result.empty() and result.back() > i and A[result.back() - 'a'] > 0)
                {
                    result.pop_back();
                }
                result.push_back(i);
            }
            int offset = i - 'a';
            --A[offset];
        }
        return result;
    }
};