// 68. Text Justification
// https://leetcode.com/problems/text-justification/

/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> result;
		int n = words.size(), i = 0;
		while (i < n) {
			int j = i, len = words[i].size(), sum = words[i].size();
			while (i + 1 < n and len + int(words[i + 1].size()) + 1 <= maxWidth) {
				len += words[i + 1].size() + 1;
				sum += words[i + 1].size();
				++i;
			}
			if (i + 1 == n) {
				string s = words[j];
				++j;
				while (j <= i) {
					s += ' ';
					s += words[j];
					++j;
				}
				s += string(maxWidth - len, ' ');
				result.push_back(s);
			}
			else if (j == i) {
				string s = words[i] + string(maxWidth - len, ' ');
				result.push_back(s);
			}
			else {
				int x = maxWidth - sum, y = i - j;
				int a = x / y, b = x % y;
				string s = words[j];
				++j;
				while (j <= i) {
					s += string(a, ' ');
					if (b > 0) {
						s += ' ';
						--b;
					}
					s += words[j];
					++j;
				}
				result.push_back(s);
			}
			++i;
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<string> words, answer, result;
	int maxWidth;

	words = {"This", "is", "an", "example", "of", "text", "justification."};
	maxWidth = 16;
	answer = {"This    is    an", "example  of text", "justification.  "};
	result = solution.fullJustify(words, maxWidth);
	assert(answer == result);

	words = {"What", "must", "be", "shall", "be."};
	maxWidth = 12;
	answer = {"What must be", "shall be.   "};
	result = solution.fullJustify(words, maxWidth);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}