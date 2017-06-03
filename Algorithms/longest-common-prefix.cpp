// 14. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/

/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		Trie trie;
		for (const auto &s : strs) {
			if (s.empty()) {
				return "";
			}
			trie.insert(s);
		}
		string result;
		Node *it = trie.root;
		while ((it = trie.getNext(it))) {
			result.push_back(it->ch);
		}
		return result;
	}
private:
	struct Node {
		Node(void) {
			cnt = 0;
			memset(nexts, 0, sizeof(nexts));
		}
		char ch;
		int cnt;
		Node* nexts[256];
	};

	struct Trie {
		Trie(void) {
			size = 0;
			root = new Node();
		}
		void insert(const string& s) {
			++size;
			Node *it = root;
			for (const auto &i : s) {
				int id = i - 0;
				if (!it->nexts[id]) {
					it->nexts[id] = new Node();

				}
				it = it->nexts[id];
				it->ch = i;
				++it->cnt;
			}
		}
		Node *getNext(Node* node) {
			if (!node) {
				return NULL;
			}
			int i = 0;
			while (i < 256 and (!node->nexts[i] or node->nexts[i]->cnt != size)) {
				++i;
			}
			return i < 256 ? node->nexts[i] : NULL;
		}
		int size;
		Node* root;
	};
};

int main(void) {
	Solution solution;
	vector<string> strs;
	string answer, result;

	strs = {"", "b"};
	answer = "";
	result = solution.longestCommonPrefix(strs);
	assert(answer == result);

	strs = {"abcd", "abc", "ab"};
	answer = "ab";
	result = solution.longestCommonPrefix(strs);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}