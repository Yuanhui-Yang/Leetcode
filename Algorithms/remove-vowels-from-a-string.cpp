1119. Remove Vowels from a String
https://leetcode.com/problems/remove-vowels-from-a-string/

Given a string S, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it, and return the new string.

 

Example 1:

Input: "leetcodeisacommunityforcoders"
Output: "ltcdscmmntyfrcdrs"
Example 2:

Input: "aeiou"
Output: ""
 

Note:

S consists of lowercase English letters only.
1 <= S.length <= 1000

class Solution {
public:
    string removeVowels(string S) {
        string t = "aeiou";
        int sz = S.size(), i = sz - 1;
        while (i >= 0)
        {
            char ch = S[i];
            if (binary_search(t.begin(), t.end(), ch))
            {
                S.erase(S.begin() + i);
            }
            --i;
        }
        return S;
    }
};