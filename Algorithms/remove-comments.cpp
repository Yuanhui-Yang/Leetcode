// 722. Remove Comments
// https://leetcode.com/problems/remove-comments/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> result;
        int sz = source.size(), i = 0, j, len;
        string s;
        while (i < sz) {
            string & line = source[i];
            len = line.size();
            j = 0;
            while (j + 1 < len) {
                if (line[j] == '/') {
                    if (line[j + 1] == '/') {
                        break;
                    }
                    if (line[j + 1] == '*') {
                        break;
                    }
                }
                ++j;
            }
            if (j + 1 < len) {
                if (line[j + 1] == '/') {
                    s = line.substr(0, j);
                    if (!s.empty()) {
                        result.push_back(s);
                    }
                    ++i;
                }
                else if (line[j + 1] == '*') {
                    s = line.substr(0, j);
                    j += 2;
                    while (j + 1 < len) {
                        if (line[j] == '*' and line[j + 1] == '/') {
                            break;
                        }
                        ++j;
                    }
                    if (j + 1 < len) {
                        j += 2;
                        s.append(line.substr(j));
                        line = s;
                    }
                    else {
                        ++i;
                        while (i < sz) {
                            string & line = source[i];
                            len = line.size();
                            j = 0;
                            while (j + 1 < len) {
                                if (line[j] == '*' and line[j + 1] == '/') {
                                    break;
                                }
                                ++j;
                            }
                            if (j + 1 < len) {
                                j += 2;
                                s.append(line.substr(j));
                                line = s;
                                break;
                            }
                            else {
                                ++i;
                            }
                        }
                    }
                }
            }
            else {
                if (!line.empty()) {
                    result.push_back(line);
                }
                ++i;
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    vector<string> source, result;
    
    source = {"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};
    result = solution.removeComments(source);
    for (const auto & i : result) {
        cout << i << '\n';
    }

    source = {"a/*comment", "line", "more_comment*/b"};
    result = solution.removeComments(source);
    for (const auto & i : result) {
        cout << i << '\n';
    }
    
    return 0;
}