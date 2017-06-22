// 208. Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/

/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
	root = new Node();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Node *it = root;
		for (const auto &ch : word) {
			int d = ch - 'a';
			if(!it->next[d]) {
				it->next[d] = new Node();
			}
			it = it->next[d];
		}
		it->isEnd = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Node *it = f(word);
		return it and it->isEnd;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		return f(prefix);
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
	Node *f(const string& word) {
		Node *it = root;
		for (const auto &ch : word) {
			int d = ch - 'a';
			if (it->next[d]) {
				it = it->next[d];
			}
			else {
				return NULL;
			}
		}
		return it;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main(void) {
	Trie trie;
	string s;
	bool answer, result;

	s = "somestring";
	trie.insert(s);
	s = "key";
	answer = false;
	result = trie.search("key");
	assert(answer == result);
	s = "some";
	answer = true;
	result = trie.startsWith(s);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}