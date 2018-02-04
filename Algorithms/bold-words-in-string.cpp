758. Bold Words in String
https://leetcode.com/problems/bold-words-in-string/

Given a set of keywords words and a string S, make all appearances of all keywords in S bold. Any letters between <b> and </b> tags become bold.

The returned string should use the least number of tags possible, and of course the tags should form a valid combination.

For example, given that words = ["ab", "bc"] and S = "aabcd", we should return "a<b>abc</b>d". Note that returning "a<b>a<b>b</b>c</b>d" would use more tags, so it is incorrect.

Note:

words has length in range [0, 50].
words[i] has length in range [1, 10].
S has length in range [0, 500].
All characters in words[i] and S are lowercase letters.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int sz = S.size(), i;
        vector<bool> A = f1(words, S);
        string result;
        for (i = 0; i < sz; ++i) {
            if (A[i]) {
                if (i == 0 or !A[i - 1]) {
                    result.append("<b>");
                }
                result.push_back(S[i]);
                if (i + 1 == sz) {
                    result.append("</b>");
                }
            }
            else {
                if (i > 0 and A[i - 1]) {
                    result.append("</b>");
                }
                result.push_back(S[i]);
            }
        }
        return result;
    }
private:
    vector<bool> f1(vector<string>& words, string & S) {
        int sz = S.size();
        vector<bool> result(sz, false);
        for (auto & word : words) {
            f2(result, S, word);
        }
        return result;
    }
    void f2(vector<bool> & A, string & text, string & pattern) {
        int sz1 = text.size(), sz2 = pattern.size(), i, j, k;
        if (sz1 < sz2) {
            return;
        }
        if (sz1 == sz2) {
            if (text == pattern) {
                for (i = 0; i < sz1; ++i) {
                    A[i] = true;
                }
            }
            return;
        }
        if (sz1 == 0 or sz2 == 0) {
            return;
        }
        vector<int> pi(sz2 + 1);
        pi[0] = -1;
        i = 0;
        j = -1;
        while (i < sz2) {
            if (j == -1 or pattern[i] == pattern[j]) {
                pi[++i] = ++j;
            }
            else {
                j = pi[j];
            }
        }
        i = 0;
        j = 0;
        while (i < sz1) {
            if (j == -1 or text[i] == pattern[j]) {
                ++i;
                ++j;
            }
            else {
                j = pi[j];
            }
            if (j == sz2) {
                for (k = 1; k <= sz2; ++k) {
                    A[i - k] = true;
                }
                i -= sz2 - 1;
                j = 0;
            }
        }
    }
};

int main(void) {
    Solution solution;
    vector<string> words;
    string S, result;
    
    words = {"ab", "bc"};
    S = "aabcd";
    result = solution.boldWords(words, S);
    cout << result << '\n';
    
    return 0;
}