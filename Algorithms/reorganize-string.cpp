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
#include <array>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        array<int, 26> A;
        A.fill(0);
        for (const auto & ch : S) {
            int offset = ch - 'a';
            ++A[offset];
        }
        priority_queue<array<int, 2>> pq;
        for (int i = 0; i < 26; ++i) {
            if (A[i] > 0) {
                pq.push({A[i], i});
            }
        }
        string result;
        while (!pq.empty()) {
            queue<array<int, 2>> q;
            for (int i = 0; i < 2 and !pq.empty(); ++i) {
                array<int, 2> top = pq.top();
                pq.pop();
                char ch = 'a' + top[1];
                if (!result.empty() and ch == result.back()) {
                    return "";
                }
                result.push_back(ch);
                if (top[0] > 1) {
                    --top[0];
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