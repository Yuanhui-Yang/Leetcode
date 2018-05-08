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

struct Node {
    bool isEnd;
    array<Node*, 26> next;
    Node() {
        isEnd = false;
        next.fill(NULL);
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
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
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return f1(word, 0, root);
    }
private:
    Node * root;
    bool f1(const string & word, int start, Node * node) {
        if (!node) {
            return false;
        }
        int sz = word.size();
        if (sz == start) {
            return node->isEnd;
        }
        char ch = word[start];
        int id = ch - 'a';
        if (ch != '.') {
            return f1(word, start + 1, node->next[id]);
        }
        for (int i = 0; i < 26; ++i) {
            if (f1(word, start + 1, node->next[i])) {
                return true;
            }
        }
        return false;
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
