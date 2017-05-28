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
		if (haystack.size() == needle.size()) {
			return haystack == needle ? 0 : -1;
		}
		if (haystack.size() < needle.size()) {
			return -1;
		}
		if (needle.empty()) {
			return 0;
		}
		int m = haystack.size(), n = needle.size(), i = 0, j = -1;
		vector<int> pi(n + 1);
		pi.front() = -1;
		while (i < n) {
			if (j == -1 or needle[i] == needle[j]) {
				pi[++i] = ++j;
			}
			else {
				j = pi[j];
			}
		}
		i = 0;
		j = 0;
		while (i < m) {
			if (j == -1 or haystack[i] == needle[j]) {
				i++;
				j++;
			}
			else {
				j = pi[j];
			}
			if (j == n) {
				return i - j;
			}
		}
		return -1;
	}
};

int main(void) {
	Solution solution;
	string haystack, needle;
	int answer, result;

	haystack = "aaa";
	needle = "a";
	answer = 0;
	result = solution.strStr(haystack, needle);
	assert(answer == result);

	haystack = "THIS IS A TEST TEXT";
	needle = "TEST";
	answer = 10;
	result = solution.strStr(haystack, needle);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}