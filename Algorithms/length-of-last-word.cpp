// 58. Length of Last Word
// https://leetcode.com/problems/length-of-last-word/

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.empty()) {
			return 0;
		}
		int n = s.size(), i = n - 1;
		while (i >= 0 and s[i] == ' ') {
			i--;
		}
		int j = i;
		while (i >= 0 and isalpha(s[i])) {
			--i;
		}
		return j - i;
	}
};

int main(void) {
	Solution solution;
	string s;
	int answer, result;

	s = "Hello World";
	answer = 5;
	result = solution.lengthOfLastWord(s);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}