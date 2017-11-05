// 720. Longest Word in Dictionary
// https://leetcode.com/problems/longest-word-in-dictionary/

/*
Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.
Example 1:
Input: 
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:
Input: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: 
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
Note:

All the strings in the input will only contain lowercase letters.
The length of words will be in the range [1, 1000].
The length of words[i] will be in the range [1, 30].
*/

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct Node {
	array<Node*, 26> next;
};

struct Comp {
	bool operator() (const string & a, const string & b) {
		return a.size() == b.size() ? a < b : a.size() < b.size();
	}
};

class Solution {
public:
	string longestWord(vector<string>& words) {
		string result;
		if (words.empty()) {
			return result;
		}
		sort(begin(words), end(words), Comp());
		if (words.front().size() > 1) {
			return result;
		}
		Node * root = new Node();
		for (const auto & word : words) {
			if (f1(root, word) and (result.size() < word.size() or (result.size() == word.size() == word < result))) {
				result = word;
			}
		}
		return result;
	}
private:
	bool f1(Node * node, const string & word) {
		if (!node) {
			return false;
		}
		int sz = word.size(), i, j;
		for (i = 0; i + 1 < sz; ++i) {
			j = word[i] - 'a';
			if (!node->next[j]) {
				return false;
			}
			node = node->next[j];
		}
		j = word.back() - 'a';
		if (!node->next[j]) {
			node->next[j] = new Node();
		}
		node = node->next[j];
		return true;
	}
};

int main(void) {
	Solution solution;
	vector<string> words;
	string result;
	
	words = {"w", "wo", "wor", "worl", "world"};
	result = solution.longestWord(words);
	cout << result << '\n';

	words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
	result = solution.longestWord(words);
	cout << result << '\n';

	return 0;
}