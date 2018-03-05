22. Generate Parentheses
https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;
        f1(result, path, 2 * n, 0, 0);
        return result;
    }
private:
    void f1(vector<string> & result, string & path, int end, int start, int diff) {
        if (diff < 0) {
            return;
        }
        if (start == end) {
            if (diff == 0) {
                result.push_back(path);
            }
            return;
        }
        path.push_back('(');
        f1(result, path, end, start + 1, diff + 1);
        path.pop_back();
        path.push_back(')');
        f1(result, path, end, start + 1, diff - 1);
        path.pop_back();
    }
};

int main(void) {
    Solution solution;
    int n;
    vector<string> result;
    
    n = 3;
    result = solution.generateParenthesis(n);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';
    
    return 0;
}