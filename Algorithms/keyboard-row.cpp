// 500. Keyboard Row
// https://leetcode.com/problems/keyboard-row/

/*
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.


American keyboard


Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		int h[26];
		memset(h, 0, sizeof(h));
		h['q' - 'a'] = 0;
		h['w' - 'a'] = 0;
		h['e' - 'a'] = 0;
		h['r' - 'a'] = 0;
		h['t' - 'a'] = 0;
		h['y' - 'a'] = 0;
		h['u' - 'a'] = 0;
		h['i' - 'a'] = 0;
		h['o' - 'a'] = 0;
		h['p' - 'a'] = 0;
		h['a' - 'a'] = 1;
		h['s' - 'a'] = 1;
		h['d' - 'a'] = 1;
		h['f' - 'a'] = 1;
		h['g' - 'a'] = 1;
		h['h' - 'a'] = 1;
		h['j' - 'a'] = 1;
		h['k' - 'a'] = 1;
		h['l' - 'a'] = 1;
		h['z' - 'a'] = 2;
		h['x' - 'a'] = 2;
		h['c' - 'a'] = 2;
		h['v' - 'a'] = 2;
		h['b' - 'a'] = 2;
		h['n' - 'a'] = 2;
		h['m' - 'a'] = 2;
		vector<string> result;
		for (const auto &word : words) {
			if (validate(word, h)) {
				result.push_back(word);
			}
		}
		return result;
	}
private:
	bool validate(const string& word, int* h) {
		for (int i = 1, n = word.size(); i < n; ++i) {
			int x = tolower(word[i]) - 'a', y = tolower(word[i - 1]) - 'a';
			if (h[x] != h[y]) {
				return false;
			}
		}
		return true;
	}
};

int main(void) {
	Solution solution;
	vector<string> words, answer, result;

	words = {"Hello", "Alaska", "Dad", "Peace"};
	sort(begin(words), end(words));
	answer = {"Alaska", "Dad"};
	sort(begin(answer), end(answer));
	result = solution.findWords(words);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}