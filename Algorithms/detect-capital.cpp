// 520. Detect Capital
// https://leetcode.com/problems/detect-capital/
#include <iostream>
#include <cassert>
#include <cctype>
#include <string>
using namespace std;
class Solution {
public:
	bool detectCapitalUse(string word) {
		if (word.empty()) {
			return false;
		}
		int mode = -1;
		for (const auto &ch : word) {
			if (isalpha(ch)) {
				if (mode == -1) {
					if (islower(ch)) {
						mode = 1;
						continue;
					}
					if (isupper(ch)) {
						mode = 0;
						continue;
					}
					continue;
				}
				if (mode == 0) {
					if (islower(ch)) {
						mode = 2;
						continue;
					}
					if (isupper(ch)) {
						mode = 3;
						continue;
					}
					continue;
				}
				if (mode == 1) {
					if (isupper(ch)) {
						return false;
					}
					continue;
				}
				if (mode == 2) {
					if (isupper(ch)) {
						return false;
					}
					continue;
				}
				if (mode == 3) {
					if (islower(ch)) {
						return false;
					}
					continue;
				}
			}
		}
		return true;
	}
};
int main(void) {
	Solution solution;
	string word;
	bool result;
	bool answer;
	
	word = "USA";
	result = solution.detectCapitalUse(word);
	answer = true;
	assert(answer == result);

	word = "FlaG";
	result = solution.detectCapitalUse(word);
	answer = false;
	assert(answer == result);

	word = "leetcode";
	result = solution.detectCapitalUse(word);
	answer = true;
	assert(answer == result);

	word = "Google";
	result = solution.detectCapitalUse(word);
	answer = true;
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}