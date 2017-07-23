// 648. Replace Words
// https://leetcode.com/problems/replace-words/

/*
In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Note:
The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000
*/

class Solution {
public:
	string replaceWords(vector<string>& dict, string sentence) {
		Trie tree;
		for (const auto & i : dict) {
			tree.insert(i);
		}
		string result;
		for (int sz = sentence.size(), i = 0; i < sz; ++i) {
			if (!isalpha(sentence[i])) {
				continue;
			}
			int j = i;
			while (i < sz and isalpha(sentence[i])) {
				++i;
			}
			string s = sentence.substr(j, i - j);
			Node * it = tree.prefix(s);
			if (it and it->isEnd and !it->word.empty()) {
				if (result.empty()) {
					result.append(it->word);
				}
				else {
					result.push_back(' ');
					result.append(it->word);
				}
			}
			else {
				if (result.empty()) {
					result.append(s);
				}
				else {
					result.push_back(' ');
					result.append(s);
				}
			}
		}
		return result;
	}
private:
	struct Node {
		array<Node*, 26> next;
		bool isEnd;
		string word;
		Node() {
			next.fill(NULL);
			isEnd = false;
			word.clear();
		}
	};
	struct Trie {
		Node * root;
		Trie() {
			root = new Node();
		}
		void insert(const string & s) {
			Node * it = root;
			for (const auto & i : s) {
				int id = i - 'a';
				if (!it->next[id]) {
					it->next[id] = new Node();
				}
				it = it->next[id];
			}
			it->isEnd = true;
			it->word = s;
		}
		Node * prefix(const string & s) {
			Node * it = root;
			for (const auto & i : s) {
				int id = i - 'a';
				if (!it) {
					return NULL;
				}
				it = it->next[id];
				if (it and it->isEnd and !it->word.empty()) {
					return it;
				}
			}
			return NULL;
		}
	};
};