// 336. Palindrome Pairs
// https://leetcode.com/problems/palindrome-pairs/

/*
Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
*/

#include <iostream>
#include <vector>
#include <list>
#include <array>

using namespace std;

struct Node {
	int id = -1;
	array<Node*, 26> A;
	list<int> B;
	Node() {
		id = -1;
		A.fill(NULL);
		B.clear();
	}
};

void gc(Node * & node) {
	if (node) {
		for (auto & i : node->A) {
			gc(i);
		}
		delete node;
		node = NULL;
	}
}

class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		Node * root = new Node();
		int sz = words.size(), i = 0;
		for (i = 0; i < sz; ++i) {
			f1(root, words[i], i);
		}
		vector<vector<int>> result;
		for (i = 0; i < sz; ++i) {
			f3(root, words[i], i, result);
		}
		gc(root);
		return result;
	}
private:
	void f1(Node * root, const string & word, const int id) {
		int sz = word.size(), i = 0, j = 0;
		
		for (i = sz - 1; i >= 0; --i) {
			if (f2(word, 0, i)) {
				root->B.push_back(id);
			}
			j = word[i] - 'a';
			if (!root->A[j]) {
				root->A[j] = new Node();
			}
			root = root->A[j];
		}
		root->B.push_back(id);
		root->id = id;
	}
	bool f2(const string & word, int i, int j) {
		while (i < j) {
			if (word[i] != word[j]) {
				return false;
			}
			++i;
			--j;
		}
		return true;
	}
	void f3(Node * root, const string & word, const int id, vector<vector<int>> & result) {
		int sz = word.size(), i = 0, j = 0;
		for (i = 0; i < sz; ++i) {
			if (root->id >= 0 and root->id != id and f2(word, i, sz - 1)) {
				result.push_back({id, root->id});
			}
			j = word[i] - 'a';
			if (!root->A[j]) {
				return;
			}
			root = root->A[j];
		}
		for (const auto & i : root->B) {
			if (id != i) {
				result.push_back({id, i});
			}
		}
	}
};

int main(void) {
	Solution solution;
	vector<string> words;
	vector<vector<int>> result;
	
	words = {"a", ""};
	result = solution.palindromePairs(words);
	for (const auto & i : result) {
		for (const auto & j : i) {
			cout << j << ' ';
		}
		cout << '\t';
	}
	cout << '\n';

	words = {"bat", "tab", "cat"};
	result = solution.palindromePairs(words);
	for (const auto & i : result) {
		for (const auto & j : i) {
			cout << j << ' ';
		}
		cout << '\t';
	}
	cout << '\n';

	words = {"abcd", "dcba", "lls", "s", "sssll"};
	result = solution.palindromePairs(words);
	for (const auto & i : result) {
		for (const auto & j : i) {
			cout << j << ' ';
		}
		cout << '\t';
	}
	cout << '\n';

	return 0;
}