// 676. Implement Magic Dictionary
// https://leetcode.com/problems/implement-magic-dictionary/

/*
Implement a magic directory with buildDict, and search methods.

For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.

For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the modified word is in the dictionary you just built.

Example 1:
Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False
Note:
You may assume that all the inputs are consist of lowercase letters a-z.
For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.
Please remember to RESET your class variables declared in class MagicDictionary, as static/class variables are persisted across multiple test cases. Please see here for more details.
*/

struct Node {
	bool isEnd;
	array<Node*, 26> next;
	Node() {
		isEnd = false;
		next.fill(NULL);
	}
};

class MagicDictionary {
public:
	/** Initialize your data structure here. */
	MagicDictionary() {
		root = new Node();
	}
	
	/** Build a dictionary through a list of words */
	void buildDict(vector<string> dict) {
		for (const auto & i : dict) {
			f1(i);
		}
	}
	
	/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
	bool search(string word) {
		return f2(word, 0, root);
	}
private:
	Node * root;
	void f1(const string & s) {
		Node * it = root;
		for (const auto & i : s) {
			int id = i - 'a';
			if (!it->next[id]) {
				it->next[id] = new Node();
			}
			it = it->next[id];
		}
		it->isEnd = true;
	}
	bool f2(const string & s, int start, Node * it) {
		if (!it) {
			return false;
		}
		int len = s.size(), i = 0;
		if (start == len) {
			return it->isEnd;
		}
		int id = s[start] - 'a';
		if (start + 1 == len) {
			for (i = 0; i < 26; ++i) {
				if (i != id and f2(s, start + 1, it->next[i])) {
					return true;
				}
			}
			return false;
		}
		if (it->next[id] and f2(s, start + 1, it->next[id])) {
			return true;
		}
		for (i = 0; i < 26; ++i) {
			if (i != id and f3(s, start + 1, it->next[i])) {
				return true;
			}
		}
		return false;
	}
	bool f3(const string & s, int i, Node * it) {
		if (!it) {
			return false;
		}
		int len = s.size();
		if (i == len) {
			return it->isEnd;
		}
		int id = s[i] - 'a';
		return f3(s, i + 1, it->next[id]);
	}
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */