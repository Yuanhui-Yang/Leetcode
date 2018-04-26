767. Reorganize String
https://leetcode.com/problems/reorganize-string/

Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        int sz = S.size();
        array<int, 26> A = f1(S);
        priority_queue<array<int, 2>> pq = f2(A);
        string result;
        while (!pq.empty()) {
            queue<array<int, 2>> q;
            for (int cnt = min(sz, 2), i = 0; i < cnt; ++i, --sz) {
                if (pq.empty()) {
                    return "";
                }
                array<int, 2> top = pq.top();
                pq.pop();
                char ch = top[1] + 'a';
                result.push_back(ch);
                --top[0];
                if (top[0] > 0) {
                    q.push(top);
                }
            }
            while (!q.empty()) {
                array<int, 2> front = q.front();
                q.pop();
                pq.push(front);
            }
        }
        return result;
    }
private:
    array<int, 26> f1(string & S) {
        array<int, 26> result;
        result.fill(0);
        for (const auto & ch : S) {
            int id = ch - 'a';
            ++result[id];
        }
        return result;
    }
    priority_queue<array<int, 2>> f2(array<int, 26> & A) {
        priority_queue<array<int, 2>> result;
        for (int i = 0; i < 26; ++i) {
            if (A[i] > 0) {
                result.push({A[i], i});
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    string S, result;

    S = "aab";
    result = solution.reorganizeString(S);
    cout << result << '\n';

    S = "aaab";
    result = solution.reorganizeString(S);
    cout << result << '\n';

    return 0;
}
