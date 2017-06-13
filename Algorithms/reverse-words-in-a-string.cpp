// 151. Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/

/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		while (!s.empty() and s.back() == ' ') {
			s.pop_back();
		}
		reverse(begin(s), end(s));
		while (!s.empty() and s.back() == ' ') {
			s.pop_back();
		}
		for (int n = s.size(), i = 0; i < n; ++i) {
			if (s[i] == ' ') {
				int j = i;
				while (i + 1 < n and s[i + 1] == ' ') {
					++i;
				}
				s.erase(next(begin(s), j), next(begin(s), i));
				n -= i - j;
				i -= i - j;
			}
			else {
				int j = i;
				while (i + 1 < n and s[i + 1] != ' ') {
					++i;
				}
				reverse(next(begin(s), j), next(begin(s), i + 1));
			}
		}
	}
};

int main(void) {
	Solution solution;
	string s, answer;

	s = "   a   ";
	answer = "a";
	solution.reverseWords(s);
	assert(s == answer);

	s = "   a   b ";
	answer = "b a";
	solution.reverseWords(s);
	assert(s == answer);

	s = "   a   b  c d   e  ";
	answer = "e d c b a";
	solution.reverseWords(s);
	assert(s == answer);

	s = "the sky is blue";
	answer = "blue is sky the";
	solution.reverseWords(s);
	assert(s == answer);

	s = " ";
	answer = "";
	solution.reverseWords(s);
	assert(s == answer);

	cout << "\nPassed All\n";
	return 0;
}