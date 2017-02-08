// 472. Concatenated Words
// https://leetcode.com/problems/concatenated-words/
#include <iostream>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/72160/simple-java-trie-dfs-solution-144ms
// struct TrieNode {
// 	TrieNode() {
// 		memset(links, 0, 26 * sizeof(TrieNode*));
// 		isEnd = false;
// 		added = false;
// 		str.clear();
// 	}
// 	TrieNode *links[26];
// 	bool isEnd;
// 	bool added;
// 	string str;
// };
// class TrieTree {
// public:
// 	TrieTree() {
// 		root = new TrieNode();
// 	}
// public:
// 	TrieNode *insert(const string& str) {
// 		TrieNode *it(root);
// 		for (const auto &ch : str) {
// 			const int idx = ch - 'a';
// 			if (!it->links[idx]) {
// 				it->links[idx] = new TrieNode();
// 			}
// 			it = it->links[idx];
// 		}
// 		it->str = str;
// 		return it;
// 	}
// public:
// 	vector<string> findAllConcatenatedWordsInADict() {
// 		vector<string> result;
// 		list<pair<TrieNode*, TrieNode*>> stack;
// 		stack.push_back(make_pair(root, root));
// 		while (!stack.empty()) {
			
// 		}
// 		return result;
// 	}
// private:
// 	TrieNode *root;
// };
class Solution {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		if (words.empty()) {
			return {};
		}
		TrieTree trieTree;
		for (const auto &word : words) {
			trieTree.insert(word);
		}
		return trieTree.findAllConcatenatedWordsInADict();
	}
};
// END: https://discuss.leetcode.com/topic/72160/simple-java-trie-dfs-solution-144ms
int main(void) {
	Solution solution;
	vector<string> words;
	vector<string> result;

	words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
	result = solution.findAllConcatenatedWordsInADict(words);
	cout << '\n';
	for (const auto &i : result) {
		cout << i << '\t';
	}
	cout << '\n';
	assert(unordered_multiset<string>({"catsdogcats", "dogcatsdog", "ratcatdogcat"}) == unordered_multiset<string>(begin(result), end(result)));

	cout << "\nPassed All\n";
	return 0;
}