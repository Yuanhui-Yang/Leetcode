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
#include <array>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int sz1 = S.size(), sz2 = 0, i = 0, j = 0;
        vector<array<int, 2>> A = f1(words, S);
        if (A.empty()) {
            return S;
        }
        sz2 = A.size();
        string result;
        while (i < sz1) {
            if (j < sz2) {
                result.append(S.substr(i, A[j][0] - i));
                result.append("<b>");
                i = A[j][0];
                result.append(S.substr(i, A[j][1] - A[j][0]));
                i = A[j][1];
                result.append("</b>");
                ++j;
            }
            else {
                result.append(S.substr(i, sz1 - i));
                i = sz1;
            }
        }
        return result;
    }
private:
    vector<array<int, 2>> f1(vector<string>& words, string & S) {
        int sz = S.size();
        vector<array<int, 2>> result;
        for (auto & word : words) {
            vector<array<int, 2>> curr = f2(S, word);
            result.insert(result.end(), curr.begin(), curr.end());
        }
        return f3(result);
    }
    vector<array<int, 2>> f2(string & text, string & pattern) {
        int sz1 = text.size(), sz2 = pattern.size(), i, j;
        if (sz1 < sz2) {
            return {};
        }
        if (sz1 == sz2) {
            if (text == pattern) {
                return {{0, sz1}};
            }
            return {};
        }
        if (sz1 == 0 or sz2 == 0) {
            return {};
        }
        vector<array<int, 2>> result;
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
                i -= sz2;
                j = -1;
                result.push_back({i, i + sz2});
            }
        }
        return result;
    }
    vector<array<int, 2>> f3(vector<array<int, 2>> & A) {
        sort(A.begin(), A.end());
        vector<array<int, 2>> result;
        int sz = A.size(), i = 0;
        while (i < sz) {
            int begin = A[i][0], end = A[i][1];
            ++i;
            while (i < sz and A[i][0] <= end) {
                end = max(end, A[i][1]);
                ++i;
            }
            result.push_back({begin, end});
        }
        return result;
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