// 208. Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/

/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    bool isEnd;
    array<Node*, 26> next;
    Node() {
        isEnd = false;
        next.fill(NULL);
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node * node = root;
        for (const auto & ch : word) {
            int id = ch - 'a';
            if (!node->next[id]) {
                node->next[id] = new Node();
            }
            node = node->next[id];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node * node = root;
        for (const auto & ch : word) {
            int id = ch - 'a';
            if (!node->next[id]) {
                return false;
            }
            node = node->next[id];
        }
        return node and node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node * node = root;
        for (const auto & ch : prefix) {
            int id = ch - 'a';
            if (!node->next[id]) {
                return false;
            }
            node = node->next[id];
        }
        return node;
    }
private:
    Node * root;
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
