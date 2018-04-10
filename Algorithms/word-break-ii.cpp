// 140. Word Break II
// https://leetcode.com/problems/word-break-ii/

/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> A(wordDict.begin(), wordDict.end());
        int sz = s.size();
        vector<bool> B(sz + 1, false);
        B[0] = true;
        for (int i = 1; i <= sz; ++i) {
            for (int j = i - 1; j >= 0 and !B[i]; --j) {
                string t = s.substr(j, i - j);
                B[i] = B[j] and A.count(t);
            }
        }
        if (!B[sz]) {
            return {};
        }
        vector<vector<string>> C(sz + 1);
        for (int i = 1; i <= sz; ++i) {
            for (int j = 0; j < i; ++j) {
                string t = s.substr(j, i - j);
                if (A.count(t)) {
                    if (j == 0) {
                        C[i].push_back(t);
                    }
                    else {
                        for (const auto & k : C[j]) {
                            string l = k;
                            l.push_back(' ');
                            l.append(t);
                            C[i].push_back(l);
                        }
                    }
                }
            }
        }
        return C[sz];
    }
};
