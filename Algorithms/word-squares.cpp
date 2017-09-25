// 425. Word Squares
// https://leetcode.com/problems/word-squares/

/*
Given a set of words (without duplicates), find all word squares you can build from them.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

b a l l
a r e a
l e a d
l a d y
Note:
There are at least 1 and at most 1000 words.
All words will have the exact same length.
Word length is at least 1 and at most 5.
Each word contains only lowercase English alphabet a-z.
Example 1:

Input:
["area","lead","wall","lady","ball"]

Output:
[
  [ "wall",
	"area",
	"lead",
	"lady"
  ],
  [ "ball",
	"area",
	"lead",
	"lady"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
Example 2:

Input:
["abat","baba","atan","atal"]

Output:
[
  [ "baba",
	"abat",
	"baba",
	"atan"
  ],
  [ "baba",
	"abat",
	"baba",
	"atal"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
*/

// Given a set of words (without duplicates), find all word squares you can build from them.

// A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

// For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

// b a l l
// a r e a
// l e a d
// l a d y
// Note:
// There are at least 1 and at most 1000 words.
// All words will have the exact same length.
// Word length is at least 1 and at most 5.
// Each word contains only lowercase English alphabet a-z.
// Example 1:

// Input:
// ["area","lead","wall","lady","ball"]

// Output:
// [
//   [ "wall",
//     "area",
//     "lead",
//     "lady"
//   ],
//   [ "ball",
//     "area",
//     "lead",
//     "lady"
//   ]
// ]

// Explanation:
// The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
// Example 2:

// Input:
// ["abat","baba","atan","atal"]

// Output:
// [
//   [ "baba",
//     "abat",
//     "baba",
//     "atan"
//   ],
//   [ "baba",
//     "abat",
//     "baba",
//     "atal"
//   ]
// ]

// Explanation:
// The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <queue>

using namespace std;

class Solution {
public:
	vector<vector<string>> wordSquares(vector<string>& words) {
		vector<vector<string>> result;
		if (words.empty()) {
			return result;
		}
		root = new Node();
		for (const auto & i : words) {
			f1(i);
		}
		vector<string> v;
		for (const auto & i : words) {
			v.push_back(i);
			f2(result, v);
			v.pop_back();
		}
		return result;
	}
private:
	void f1(const string & s) {
		Node * node = root;
		for (const auto & i : s) {
			int id = i - 'a';
			if (!node->next[id]) {
				node->next[id] = new Node();
			}
			node = node->next[id];
		}
		node->isEnd = true;
		node->str = s;
	}

	void f2(vector<vector<string>> & result, vector<string> & v) {
		int X = v.size(), Y = v[0].size();
		if (X == Y) {
			result.push_back(v);
			return;
		}
		string prefix;
		for (int i = 0; i < X; ++i) {
			prefix.push_back(v[i][X]);
		}
		vector<string> strs = f3(prefix);
		for (const auto & i : strs) {
			v.push_back(i);
			f2(result, v);
			v.pop_back();
		}
	}

	vector<string> f3(const string & prefix) {
		vector<string> result;
		Node * node = root;
		for (const auto & i : prefix) {
			int id = i - 'a';
			if (!node->next[id]) {
				return result;
			}
			node = node->next[id];
		}
		queue<Node *> curr;
		if (node) {
			curr.push(node);
		}
		while (!curr.empty()) {
			node = curr.front();
			curr.pop();
			if (node->isEnd) {
				result.push_back(node->str);
			}
			for (int i = 0; i < 26; ++i) {
				if (node->next[i]) {
					curr.push(node->next[i]);
				}
			}
		}
		return result;
	}

	struct Node {
		bool isEnd;
		string str;
		array<Node *, 26> next;
		Node() {
			isEnd = false;
			str.clear();
			next.fill(NULL);
		}
	};

	Node * root;
};

int main(void) {
	Solution solution;
	vector<string> words;
	vector<vector<string>> result;
	
	words = {"area", "lead", "wall", "lady", "ball"};
	result = solution.wordSquares(words);
	for (const auto & i : result) {
		for (const auto & j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	
	return 0;
}