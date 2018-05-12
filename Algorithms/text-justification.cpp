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
        for (int sz = words.size(), i = 0; i < sz; ++i) {
            int j = i, a = words[i].size(), b = words[i].size();
            while (i + 1 < sz and a + words[i + 1].size() + 1 <= maxWidth) {
                a += words[i + 1].size() + 1;
                b += words[i + 1].size();
                ++i;
            }
            string s;
            if (i + 1 == sz) {
                s.append(words[j]);
                ++j;
                while (j <= i) {
                    s.push_back(' ');
                    s.append(words[j]);
                    ++j;
                }
            }
            else if (i == j) {
                s.append(words[i]);
            }
            else {
                int c = maxWidth - b, d = i - j, x = c / d, y = c % d;
                s.append(words[j]);
                ++j;
                while (j <= i) {
                    if (y > 0) {
                        --y;
                        s.push_back(' ');
                    }
                    s.append(string(x, ' '));
                    s.append(words[j]);
                    ++j;
                }
            }
            while (s.size() < maxWidth) {
                s.push_back(' ');
            }
            result.push_back(s);
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
