#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        result.push_back(S);
        for (int sz = S.size(), i = 0; i < sz; ++i) {
            char ch = S[i];
            if (isalpha(ch)) {
                vector<string> next;
                for (auto & s : result) {
                    s[i] = tolower(s[i]);
                    next.push_back(s);
                    s[i] = toupper(s[i]);
                    next.push_back(s);
                }
                result = next;
            }
        }
        return result;
    }
};

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
