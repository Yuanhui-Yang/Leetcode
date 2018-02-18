686. Repeated String Match
https://leetcode.com/problems/repeated-string-match/

Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int result = 1;
        string s = A;
        vector<int> next = f1(B);
        while (true) {
            if (A.size() < B.size()) {
                A.append(s);
            }
            else if (f2(A, B, next) >= 0) {
                return result;
            }
            else if (A.size() >= s.size() + B.size()) {
                return -1;
            }
            else {
                A.append(s);
            }
            ++result;
        }
        return -1;
    }
private:
    vector<int> f1(string & pattern) {
        int sz = pattern.size();
        vector<int> result(sz + 1);
        result[0] = -1;
        int i = 0, j = -1;
        while (i < sz) {
            if (j == -1 or pattern[i] == pattern[j]) {
                result[++i] = ++j;
            }
            else {
                j = result[j];
            }
        }
        return result;
    }
    int f2(string & text, string & pattern, vector<int> & next) {
        int sz1 = text.size(), sz2 = pattern.size(), i = 0, j = 0;
        while (i < sz1) {
            if (j == -1 or text[i] == pattern[j]) {
                ++i;
                ++j;
            }
            else {
                j = next[j];
            }
            if (j == sz2) {
                return i - sz2;
            }
        }
        return -1;
    }
};

int main(void) {
    Solution solution;
    string A, B;
    int result;
    
    A = "abcd";
    B = "cdabcdab";
    result = solution.repeatedStringMatch(A, B);
    cout << result << '\n';
    
    return 0;
}