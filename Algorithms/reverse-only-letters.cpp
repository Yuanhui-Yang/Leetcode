917. Reverse Only Letters
https://leetcode.com/problems/reverse-only-letters/

Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

 

Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 

Note:

S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S doesn't contain \ or "

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int sz = S.size(), i = 0, j = sz - 1;
        while (i < j)
        {
            char & ch1 = S[i], & ch2 = S[j];
            if (!isalpha(ch1))
            {
                ++i;
            }
            else if (!isalpha(ch2))
            {
                --j;
            }
            else
            {
                swap(ch1, ch2);
                ++i;
                --j;
            }
        }
        return S;
    }
};