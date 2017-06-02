// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int result = 0;
		vector<int> p(256, -1);
		for (int i = 0, n = s.size(), j = -1; i < n; ++i) {
			j = max(j, p[s[i]]);
			result = max(result, i - j);
			p[s[i]] = i;
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	string s;
	int answer, result;

	s = "abcabcbb";
	answer = 3;
	result = solution.lengthOfLongestSubstring(s);
	assert(answer == result);

	s = "bbbbb";
	answer = 1;
	result = solution.lengthOfLongestSubstring(s);
	assert(answer == result);

	s = "pwwkew";
	answer = 3;
	result = solution.lengthOfLongestSubstring(s);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}