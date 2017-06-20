// 244. Shortest Word Distance II
// https://leetcode.com/problems/shortest-word-distance-ii/

/*
This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

#include <bits/stdc++.h>
using namespace std;

class WordDistance {
public:
	WordDistance(vector<string> words) {
		h.clear();
		for (int n = words.size(), i = 0; i < n; ++i) {
			h[words[i]].push_back(i);
		}
	}

	int shortest(string word1, string word2) {
		if (!h.count(word1) or !h.count(word2)) {
			return INT_MAX;
		}
		const vector<int>& a = h[word1], &b = h[word2];
		int result = INT_MAX, i = 0, j = 0, m = a.size(), n = b.size();
		while (i < m and j < n) {
			result = min(result, abs(a[i] - b[j]));
			a[i] < b[j] ? ++i : ++j;
		}
		return result;
	}
private:
	unordered_map<string, vector<int>> h;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */

int main(void) {
	WordDistance wordDistance({});
	vector<string> words;
	string word1, word2;
	int answer, result;

	words = {"practice", "makes", "perfect", "coding", "makes"};
	wordDistance = WordDistance(words);
	word1 = "coding";
	word2 = "practice";
	answer = 3;
	result = wordDistance.shortest(word1, word2);
	assert(answer == result);

	words = {"practice", "makes", "perfect", "coding", "makes"};
	wordDistance = WordDistance(words);
	word1 = "makes";
	word2 = "coding";
	answer = 1;
	result = wordDistance.shortest(word1, word2);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}