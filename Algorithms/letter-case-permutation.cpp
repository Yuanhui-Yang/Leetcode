784. Letter Case Permutation
https://leetcode.com/problems/letter-case-permutation/

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length at most 12.
S will consist only of letters or digits.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        string path;
        f1(result, path, S, 0);
        return result;
    }
private:
    void f1(vector<string> & result, string & path, string & S, int begin) {
        int end = S.size();
        if (begin >= end) {
            result.push_back(path);
            return;
        }
        if (isdigit(S[begin])) {
            path.push_back(S[begin]);
            f1(result, path, S, begin + 1);
            path.pop_back();
            return;
        }
        path.push_back(tolower(S[begin]));
        f1(result, path, S, begin + 1);
        path.pop_back();
        path.push_back(toupper(S[begin]));
        f1(result, path, S, begin + 1);
        path.pop_back();
    }
};

int main(void) {
    Solution solution;
    string S;
    vector<string> result;
    
    S = "a1b2";
    result = solution.letterCasePermutation(S);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    S = "3z4";
    result = solution.letterCasePermutation(S);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    S = "12345";
    result = solution.letterCasePermutation(S);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';
    
    return 0;
}