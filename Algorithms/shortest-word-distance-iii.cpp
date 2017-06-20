// 245. Shortest Word Distance III
// https://leetcode.com/problems/shortest-word-distance-iii/

/*
This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int shortestWordDistance(vector<string>& words, string word1, string word2) {
		int n = words.size(), result = n;
		for (int i = 0, x = -1, y = -1; i < n; ++i) {
			const string &word = words[i];
			if (word == word1 and word == word2) {
				x < y ? x = i : y = i;
			}
			else if (word == word1 or word == word2) {
				if (word == word1) {
					x = i;
				}
				if (word == word2) {
					y = i;
				}
			}
			if (x >= 0 and y >= 0) {
				result = min(result, abs(x - y));
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<string> words;
	string word1, word2;
	int answer, result;

	words = {"practice", "makes", "perfect", "coding", "makes"};
	word1 = "makes";
	word2 = "coding";
	answer = 1;
	result = solution.shortestWordDistance(words, word1, word2);
	assert(answer == result);

	words = {"practice", "makes", "perfect", "coding", "makes"};
	word1 = "makes";
	word2 = "makes";
	answer = 3;
	result = solution.shortestWordDistance(words, word1, word2);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}