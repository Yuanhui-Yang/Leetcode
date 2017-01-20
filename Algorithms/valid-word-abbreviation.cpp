// 408. Valid Word Abbreviation
// https://leetcode.com/problems/valid-word-abbreviation/
#include <iostream>
#include <cassert>
#include <string>
using namespace std;
class Solution {
public:
	bool validWordAbbreviation(string word, string abbr) {
		if (abbr.size() > word.size()) {
			return false;
		}
		size_t i = 0, j = 0;
		for (i = 0, j = 0; i < abbr.size(); i++) {
			if (j >= word.size()) {
				return false;
			}
			if (abbr[i] >= 'a' && abbr[i] <= 'z') {
				if (abbr[i] == word[j]) {
					j++;
					continue;
				}
				if (abbr[i] != word[j]) {
					return false;
				}
				continue;
			}
			if (abbr[i] >= '0' && abbr[i] <= '9') {
				if (abbr[i] == '0') {
					return false;
				}
				size_t k = i;
				while (i < abbr.size() && abbr[i] >= '0' && abbr[i] <= '9') {
					i++;
				}
				size_t step = stoul(abbr.substr(k, i--));
				j += step;
				continue;
			}
		}
		return j == word.size();
	}
};
int main(void) {
	Solution solution;
	bool result;

	result = solution.validWordAbbreviation("internationalization", "i12iz4n");
	assert(true == result);

	result = solution.validWordAbbreviation("apple", "a2e");
	assert(false == result);

	result = solution.validWordAbbreviation("abbreviation", "a10n");
	assert(true == result);

	result = solution.validWordAbbreviation("hi", "02");
	assert(false == result);	

	cout << "\nPassed All\n";
	return 0;
}