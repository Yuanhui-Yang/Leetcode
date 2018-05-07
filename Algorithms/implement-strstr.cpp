// 28. Implement strStr()
// https://leetcode.com/problems/implement-strstr/

/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        f1(needle);
        return f2(haystack, needle);
    }
private:
    vector<int> A;
    void f1(string & s) {
        int sz = s.size(), i = 0, j = -1;
        A.resize(sz + 1);
        A[0] = -1;
        while (i < sz) {
            if (j == -1 or s[i] == s[j]) {
                A[++i] = ++j;
            }
            else {
                j = A[j];
            }
        }
    }
    int f2(string & haystack, string & needle) {
        int sz1 = haystack.size(), sz2 = needle.size(), i = 0, j = 0;
        while (i < sz1) {
            if (j == -1 or haystack[i] == needle[j]) {
                ++i;
                ++j;
            }
            else {
                j = A[j];
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
	string haystack, needle;
	int answer, result;

	haystack = "mississippi";
	needle = "issipi";
	answer = -1;
	result = solution.strStr(haystack, needle);
	assert(answer == result);

	haystack = "mississippi";
	needle = "issip";
	answer = 4;
	result = solution.strStr(haystack, needle);
	assert(answer == result);

	haystack = "mississippi";
	needle = "issip";
	answer = 4;
	result = solution.strStr(haystack, needle);
	assert(answer == result);

	haystack = "aaaa";
	needle = "baaa";
	answer = -1;
	result = solution.strStr(haystack, needle);
	assert(answer == result);

	haystack = "a";
	needle = "";
	answer = 0;
	result = solution.strStr(haystack, needle);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
