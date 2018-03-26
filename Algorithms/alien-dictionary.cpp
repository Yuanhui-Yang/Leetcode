269. Alien Dictionary
https://leetcode.com/problems/alien-dictionary/

There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:
Given the following words in dictionary,

[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".

Example 2:
Given the following words in dictionary,

[
  "z",
  "x"
]
The correct order is: "zx".

Example 3:
Given the following words in dictionary,

[
  "z",
  "x",
  "z"
]
The order is invalid, so return "".

Note:
You may assume all letters are in lowercase.
You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        f1(words);
        return f2();
    }
private:
    array<array<int, 26>, 26> A;
    array<int, 26> B;
    array<bool, 26> C;
    void f1(vector<string> & words) {
        for (int i = 0; i < 26; ++i) {
            A[i].fill(false);
        }
        B.fill(0);
        C.fill(false);
        int sz = words.size();
        if (sz > 0) {
            for (const auto & ch : words[0]) {
                int id = ch - 'a';
                C[id] = true;
            }   
        }
        for (int i = 0; i + 1 < sz; ++i) {
            string a = words[i], b = words[i + 1];
            for (const auto & ch : b) {
                int id = ch - 'a';
                C[id] = true;
            }
            int j = 0, k = min(a.size(), b.size());
            while (j < k and a[j] == b[j]) {
                ++j;
            }
            if (j < k) {
                int x = a[j] - 'a', y = b[j] - 'a';
                if (!A[x][y]) {
                    A[x][y] = true;
                    ++B[y];
                }
            }
        }
    }
    string f2() {
        queue<int> q;
        for (int i = 0; i < 26; ++i) {
            if (C[i] and B[i] == 0) {
                q.push(i);
            }
        }
        string result;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            char ch = front + 'a';
            result.push_back(ch);
            for (int i = 0; i < 26; ++i) {
                if (A[front][i]) {
                    A[front][i] = false;
                    --B[i];
                    if (B[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (A[i][j]) {
                    return "";
                }
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<string> words;
    string result;

    words = {"bsusz", "rhn", "gfbrwec"," kuw", "qvpxbexnhx", "gnp", "laxutz", "qzxccww"};
    result = solution.alienOrder(words);
    cout << result << '\n';

    words = {"wrt", "wrf", "er", "ett", "rftt"};
    result = solution.alienOrder(words);
    cout << result << '\n';

    words = {"z", "x"};
    result = solution.alienOrder(words);
    cout << result << '\n';

    words = {"z", "x", "z"};
    result = solution.alienOrder(words);
    cout << result << '\n';

    return 0;
}