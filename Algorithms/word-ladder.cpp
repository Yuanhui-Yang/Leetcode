// 127. Word Ladder
// https://leetcode.com/problems/word-ladder/

/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		int sz = wordList.size(), i, j, k;
		if (sz == 0 or beginWord == endWord) {
			return 0;
		}
		i = 0;
		while (i < sz and wordList[i] != endWord) {
			++i;
		}
		if (i == sz) {
			return 0;
		}
		k = i;
		vector<vector<int>> A(sz);
		for (i = 0; i + 1 < sz; ++i) {
			for (j = i + 1; j < sz; ++j) {
				if (f(wordList[i], wordList[j])) {
					A[i].push_back(j);
					A[j].push_back(i);
				}
			}
		}
		queue<int> curr;
		vector<bool> B(sz, true);
		for (i = 0; i < sz; ++i) {
			if (f(beginWord, wordList[i])) {
				curr.push(i);
				B[i] = false;
			}
		}
		int result = 1;
		while (!curr.empty()) {
			++result;
			sz = curr.size();
			for (i = 0; i < sz; ++i) {
				j = curr.front();
				if (j == k) {
					return result;
				}
				curr.pop();
				for (const auto & l : A[j]) {
					if (B[l]) {
						B[l] = false;
						curr.push(l);
					}
				}
			}
		}
		return 0;
	}
private:
	bool f(const string & x, const string & y) {
		int sz1 = x.size(), sz2 = y.size(), i = 0, cnt = 0;
		if (sz1 != sz2) {
			return false;
		}
		while (i < sz1 and cnt <= 1) {
			if (x[i] != y[i]) {
				++cnt;
			}
			++i;
		}
		return i == sz1 and cnt == 1;
	}
};

int main(void) {
	Solution solution;
	string beginWord, endWord;
	vector<string> wordList;
	int result;
	
	beginWord = "hit";
	endWord = "cog";
	wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
	result = solution.ladderLength(beginWord, endWord, wordList);
	cout << result << '\n';
	
	return 0;
}