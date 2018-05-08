// 71. Simplify Path
// https://leetcode.com/problems/simplify-path/

/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string word, result;
        stringstream ss(path);
        vector<string> A;
        while (getline(ss, word, '/')) {
            if (word == "" or word == ".") {
                
            }
            else if (word == ".." and !A.empty()) {
                A.pop_back();
            }
            else if (word != "..") {
                A.push_back(word);
            }
        }
        for (const auto & i : A) {
            result.push_back('/');
            result.append(i);
        }
        if (result.empty()) {
            result = "/";
        }
        return result;
    }
};

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> v;
		for (int n = path.size(), i = 0; i < n; ++i) {
			if (path[i] == '/') {
				continue;
			}
			int j = i;
			while (i < n and path[i] != '/') {
				++i;
			}
			string s = path.substr(j, i - j);
			if (s == "" or s == ".") {
				continue;
			}
			if (s == "..") {
				if (!v.empty()) {
					v.pop_back();
				}
				continue;
			}
			v.push_back("/" + s);
		}
		return v.empty() ? string("/") : accumulate(begin(v), end(v), string(""));
	}
};

int main(void) {
	Solution solution;
	string path, answer, result;

	path = "/";
	answer = "/";
	result = solution.simplifyPath(path);
	assert(answer == result);

	path = "/home/";
	answer = "/home";
	result = solution.simplifyPath(path);
	assert(answer == result);

	path = "/a/./b/../../c/";
	answer = "/c";
	result = solution.simplifyPath(path);
	assert(answer == result);

	path = "/..";
	answer = "/";
	result = solution.simplifyPath(path);
	assert(answer == result);

	path = "/../";
	answer = "/";
	result = solution.simplifyPath(path);
	assert(answer == result);

	path = "/home//foo/";
	answer = "/home/foo";
	result = solution.simplifyPath(path);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
