1087. Brace Expansion
https://leetcode.com/problems/brace-expansion/

A string S represents a list of words.

Each letter in the word has 1 or more options.  If there is one option, the letter is represented as is.  If there is more than one option, then curly braces delimit the options.  For example, "{a,b,c}" represents options ["a", "b", "c"].

For example, "{a,b,c}d{e,f}" represents the list ["ade", "adf", "bde", "bdf", "cde", "cdf"].

Return all words that can be formed in this manner, in lexicographical order.

 

Example 1:

Input: "{a,b}c{d,e}f"
Output: ["acdf","acef","bcdf","bcef"]
Example 2:

Input: "abcd"
Output: ["abcd"]
 

Note:

1 <= S.length <= 50
There are no nested curly brackets.
All characters inside a pair of consecutive opening and ending curly brackets are different.

class Solution {
public:
    vector<string> expand(string S) {
        vector<string> result;
        int sz = S.size(), i = 0;
        while (i < sz)
        {
            char ch = S[i];
            vector<string> A;
            if (ch == '{')
            {
                ++i;
                while (i < sz and S[i] != '}')
                {
                    string t;
                    while (i < sz and S[i] != ',' and S[i] != '}')
                    {
                        t.push_back(S[i]);
                        ++i;
                    }
                    if (i < sz and S[i] == ',')
                    {
                        ++i;
                    }
                    A.push_back(t);
                }
                ++i;
            }
            else
            {
                string t;
                while (i < sz and S[i] != ',' and S[i] != '{' and S[i] != '}')
                {
                    t.push_back(S[i]);
                    ++i;
                }
                A.push_back(t);
            }
            if (result.empty())
            {
                swap(A, result);
            }
            else
            {
                vector<string> B;
                for (auto & i : result)
                {
                    for (auto & j : A)
                    {
                        B.push_back(i + j);
                    }
                }
                swap(B, result);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};