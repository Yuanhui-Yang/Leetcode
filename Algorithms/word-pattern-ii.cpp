#include <iostream>
#include <string>
#include <array>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        array<string, 26> A;
        A.fill(string(""));
        unordered_set<string> B;
        return f1(A, B, pattern, 0, pattern.size(), str, 0, str.size());
    }
private:
    bool f1(array<string, 26> & A, unordered_set<string> & B, const string & pattern, int begin1, const int end1, const string & str, int begin2, const int end2) {
        if (begin1 == end1 or begin2 == end2) {
            return begin1 == end1 and begin2 == end2;
        }
        int i = pattern[begin1] - 'a', j;
        string s;
        if (A[i].empty()) {
            for (j = begin2 + 1; j <= end2; ++j) {
                s = str.substr(begin2, j - begin2);
                if (!B.count(s)) {
                    A[i] = s;
                    B.insert(s);
                    if (f1(A, B, pattern, begin1 + 1, end1, str, j, end2)) {
                        return true;
                    }
                    B.erase(s);
                    A[i].clear();
                }
            }
            return false;
        }
        j = begin2 + A[i].size();
        s = str.substr(begin2, A[i].size());
        if (A[i] == s) {
            return f1(A, B, pattern, begin1 + 1, end1, str, j, end2);
        }
        return false;
    }
};

int main(void) {
    Solution solution;
    string pattern, str;
    bool result;
    
    pattern = "abab";
    str = "redblueredblue";
    result = solution.wordPatternMatch(pattern, str);
    cout << boolalpha << result << '\n';

    pattern = "aaaa";
    str = "asdasdasdasd";
    result = solution.wordPatternMatch(pattern, str);
    cout << boolalpha << result << '\n';

    pattern = "aabb";
    str = "xyzabcxzyabc";
    result = solution.wordPatternMatch(pattern, str);
    cout << boolalpha << result << '\n';

    pattern = "ab";
    str = "aa";
    result = solution.wordPatternMatch(pattern, str);
    cout << boolalpha << result << '\n';

    return 0;
}
