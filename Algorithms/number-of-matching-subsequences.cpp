792. Number of Matching Subsequences
https://leetcode.com/problems/number-of-matching-subsequences/

Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].

#include <iostream>
#include <queue>
#include <array>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        f1(words);
        return f2(S, words);
    }
private:
    array<queue<array<size_t, 2>>, 26> A;
    void f1(vector<string>& words) {
        for (size_t sz = words.size(), i = 0; i < sz; ++i) {
            string & word = words[i];
            int id = word[0] - 'a';
            A[id].push({i, 0});
        }
    }
    int f2(string & S, vector<string>& words) {
        int result = 0;
        for (const auto & ch : S) {
            int id = ch - 'a';
            queue<array<size_t, 2>> & q = A[id];
            int sz = q.size();
            while (sz-- > 0) {
                array<size_t, 2> front = q.front();
                q.pop();
                ++front[1];
                string & word = words[front[0]];
                if (front[1] == word.size()) {
                    ++result;
                }
                else {
                    int nid = word[front[1]] - 'a';
                    A[nid].push(front);
                }
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    string S;
    vector<string> words;
    int result;

    S = "abcde";
    words = {"a", "bb", "acd", "ace"};
    result = solution.numMatchingSubseq(S, words);
    cout << result << '\n';

    return 0;
}

#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        f1(S);
        int result = 0;
        for (auto & word : words) {
            result += f2(word);
        }
        return result;
    }
private:
    array<vector<int>, 26> A;
    void f1(string & S) {
        for (int sz = S.size(), i = 0; i < sz; ++i) {
            int id = S[i] - 'a';
            A[id].push_back(i);
        }
    }
    bool f2(string & word) {
        int prev = -1;
        for (const auto & ch : word) {
            int id = ch - 'a';
            vector<int> & v = A[id];
            vector<int>::iterator curr = upper_bound(v.begin(), v.end(), prev);
            if (curr == v.end()) {
                return false;
            }
            else {
                prev = *curr;
            }
        }
        return true;
    }
};

int main(void) {
    Solution solution;
    string S;
    vector<string> words;
    int result;

    S = "abcde";
    words = {"a", "bb", "acd", "ace"};
    result = solution.numMatchingSubseq(S, words);
    cout << result << '\n';

    return 0;
}
