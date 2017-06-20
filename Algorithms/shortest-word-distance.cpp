// 243. Shortest Word Distance
// https://leetcode.com/problems/shortest-word-distance/

/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int shortestDistance(vector<string>& words, string word1, string word2) {
		int n = words.size(), result = n;
		for (int i = 0, x = -1, y = -1; i < n; ++i) {
			const string& word = words[i];
			if (word == word1) {
				x = i;
			}
			if (word == word2) {
				y = i;
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
	word1 = "coding";
	word2 = "practice";
	answer = 3;
	result = solution.shortestDistance(words, word1, word2);
	assert(answer == result);

	words = {"practice", "makes", "perfect", "coding", "makes"};
	word1 = "makes";
	word2 = "coding";
	answer = 1;
	result = solution.shortestDistance(words, word1, word2);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}