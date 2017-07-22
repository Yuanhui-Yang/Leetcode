// 408. Valid Word Abbreviation
// https://leetcode.com/problems/valid-word-abbreviation/

/*
Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".

Note:
Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.

Example 1:
Given s = "internationalization", abbr = "i12iz4n":

Return true.
Example 2:
Given s = "apple", abbr = "a2e":

Return false.
*/

class Solution {
public:
	bool validWordAbbreviation(string word, string abbr) {
		int M = word.size(), N = abbr.size(), i = 0, j = 0;
		while (i < M and j < N) {
			if (isalpha(abbr[j])) {
				if (word[i] != abbr[j]) {
					return false;
				}
				++i;
				++j;
			}
			else if (abbr[j] == '0') {
				return false;
			}
			else {
				int len = 0;
				while (j < N and isdigit(abbr[j])) {
					len = 10 * len + abbr[j] - '0';
					++j;
				}
				i += len;
			}
		}
		return i == M and j == N;
	}
};