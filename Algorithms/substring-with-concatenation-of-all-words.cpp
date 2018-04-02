30. Substring with Concatenation of All Words
https://leetcode.com/problems/substring-with-concatenation-of-all-words/

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        unordered_map<string, int> A, B;
        for (const auto & word : words) {
            ++A[word];
        }
        int sz1 = s.size(), sz2 = words.size(), sz3 = words[0].size(), sz4 = sz2 * sz3, i = 0, j = 0, k = 0, cnt1 = A.size(), cnt2 = 0;
        while (i < sz3) {
            j = i;
            k = i;
            B.clear();
            cnt2 = 0;
            while (k + sz3 <= sz1) {
                string t = s.substr(k, sz3);
                ++B[t];
                if (B[t] == A[t]) {
                    ++cnt2;
                }
                k += sz3;
                while (cnt2 == cnt1) {
                    if (k - j == sz4) {
                        result.push_back(j);
                    }
                    string t = s.substr(j, sz3);
                    if (B[t] == A[t]) {
                        --cnt2;
                    }
                    --B[t];
                    j += sz3;
                }
            }
            ++i;
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    string s;
    vector<string> words;
    vector<int> result;
  
    s = "barfoothefoobarman";
    words = { "foo", "bar" };
    result = solution.findSubstring(s, words);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    return 0;
}
