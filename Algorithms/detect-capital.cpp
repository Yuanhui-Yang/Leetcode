// 520. Detect Capital
// https://leetcode.com/problems/detect-capital/

/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool detectCapitalUse(string word) {
		for (int n = word.size(), i = 0, j = -1; i < n; ++i) {
			char ch = word[i];
			if (isupper(ch)) {
				if (i - j > 1) {
					return false;
				}
				j = i;
			}
			else {
				if (j > 0) {
					return false;
				}
			}
		}
		return true;
	}
};

int main(void) {
	Solution solution;
	string word;
	bool answer, result;

	word = "ffffffffffffffffffffF";
	answer = false;
	result = solution.detectCapitalUse(word);
	assert(answer == result);

	word = "USA";
	answer = true;
	result = solution.detectCapitalUse(word);
	assert(answer == result);

	word = "FlaG";
	answer = false;
	result = solution.detectCapitalUse(word);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}