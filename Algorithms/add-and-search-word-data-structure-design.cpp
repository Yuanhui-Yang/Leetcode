// 211. Add and Search Word - Data structure design
// https://leetcode.com/problems/add-and-search-word-data-structure-design/

/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new Node();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		Node* it = root;
		for (const auto &ch : word) {
			int d = ch - 'a';
			if (!it->next[d]) {
				it->next[d] = new Node();
			}
			it = it->next[d];
		}
		it->isEnd = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return f(root, word);
	}
private:
	struct Node {
		Node(void) {
			isEnd = false;
			memset(next, 0, sizeof(next));
		}
		bool isEnd;
		Node* next[26];
	};
	Node *root;
	bool f(Node* root, const string& s) {
		if (s.empty()) {
			return root and root->isEnd;
		}
		if (!root) {
			return false;
		}
		for (int n = s.size(), i = 0; i < n; ++i) {
			char ch = s[i];
			if (ch == '.') {
				const string t = s.substr(i + 1);
				for (int j = 0; j < 26; ++j) {
					if (f(root->next[j], t)) {
						return true;
					}
				}
				return false;
			}
			int d = ch - 'a';
			if (!root->next[d]) {
				return false;
			}
			root = root->next[d];
		}
		return root->isEnd;
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

int main(void) {
	WordDictionary wordDictionary;
	string word;
	bool answer, result;

	word = "bad";
	wordDictionary.addWord(word);

	word = "dad";
	wordDictionary.addWord(word);

	word = "mad";
	wordDictionary.addWord(word);

	word = "pad";
	answer = false;
	result = wordDictionary.search(word);
	assert(answer == result);

	word = "bad";
	answer = true;
	result = wordDictionary.search(word);
	assert(answer == result);

	word = ".ad";
	answer = true;
	result = wordDictionary.search(word);
	assert(answer == result);

	word = "b..";
	answer = true;
	result = wordDictionary.search(word);
	assert(answer == result);

	wordDictionary = WordDictionary();

	word = "a";
	wordDictionary.addWord(word);

	word = "a";
	wordDictionary.addWord(word);

	word = ".";
	answer = true;
	result = wordDictionary.search(word);
	assert(answer == result);

	word = "a";
	answer = true;
	result = wordDictionary.search(word);
	assert(answer == result);

	word = "aa";
	answer = false;
	result = wordDictionary.search(word);
	assert(answer == result);

	word = "a";
	answer = true;
	result = wordDictionary.search(word);
	assert(answer == result);

	word = ".a";
	answer = false;
	result = wordDictionary.search(word);
	assert(answer == result);

	word = "a.";
	answer = false;
	result = wordDictionary.search(word);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}