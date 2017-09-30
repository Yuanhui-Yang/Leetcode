// 472. Concatenated Words
// https://leetcode.com/problems/concatenated-words/

/*
Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
All the input string will only include lower case letters.
The returned elements order does not matter.
*/

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <unordered_set>

using namespace std;

#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

struct Node {
	bool isEnd = false;
	array<Node*, 26> next;
	Node() {
		isEnd = false;
		next.fill(NULL);
	}
};

void gc(Node * & node) {
	if (node) {
		for (auto & i : node->next) {
			gc(i);
		}
		delete node;
		node = NULL;
	}
}

class Solution {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		int sz = words.size();
		vector<string> result;
		if (sz <= 2) {
			return result;
		}
		Node * root = new Node();
		for (const auto & i : words) {
			if (!i.empty()) {
				f1(root, i);
			}
		}
		for (const auto & i : words) {
			if (!i.empty() and f2(root, root, i, 0, 0)) {
				result.push_back(i);
			}
		}
		gc(root);
		return result;
	}
private:
	void f1(Node * node, const string & word) {
		int id = 0;
		for (const auto & ch : word) {
			id = ch - 'a';
			if (!node->next[id]) {
				node->next[id] = new Node();
			}
			node = node->next[id];
		}
		node->isEnd = true;
	}
	bool f2(Node * root, Node * node, const string & word, const int start, const int cnt) {
		if (!node) {
			return false;
		}
		int sz = word.size(), id = 0;
		if (start == sz) {
			return node->isEnd and cnt > 0;
		}
		id = word[start] - 'a';
		node = node->next[id];
		if (node and node->isEnd and f2(root, root, word, start + 1, cnt + 1)) {
			return true;
		}
		return f2(root, node, word, start + 1, cnt);
	}
};

int main(void) {
	Solution solution;
	vector<string> words, result;

	words = {""};
	result = solution.findAllConcatenatedWordsInADict(words);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';

	words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
	result = solution.findAllConcatenatedWordsInADict(words);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';
		
	return 0;
}

struct Comp {
	bool operator() (const string & a, const string & b) {
		return a.size() < b.size();
	}
};

class Solution {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		int sz = words.size();
		vector<string> result;
		if (sz <= 2) {
			return result;
		}
		sort(begin(words), end(words), Comp());
		unordered_set<string> A;
		for (const auto & i : words) {
			if (!i.empty() and f(A, i)) {
				result.push_back(i);
			}
			A.insert(i);
		}
		return result;
	}
private:
	bool f(const unordered_set<string> & A, const string & word) {
		int sz = word.size(), i = 0, j = 0;
		vector<bool> B(sz + 1, false);
		B[0] = true;
		for (i = 1; i <= sz; ++i) {
			for (j = 0; j < i; ++j) {
				if (B[j] and A.count(word.substr(j, i - j))) {
					B[i] = true;
					break;
				}
			}
		}
		return B[sz];
	}
};

int main(void) {
	Solution solution;
	vector<string> words, result;

	words = {""};
	result = solution.findAllConcatenatedWordsInADict(words);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';

	words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
	result = solution.findAllConcatenatedWordsInADict(words);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';
		
	return 0;
}