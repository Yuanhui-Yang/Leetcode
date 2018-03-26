269. Alien Dictionary
https://leetcode.com/problems/alien-dictionary/

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