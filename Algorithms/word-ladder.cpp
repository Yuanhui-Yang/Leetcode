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
		if (beginWord == endWord) {
			return 2;
		}
		unordered_set<string> words(begin(wordList), end(wordList));
		if (!words.count(endWord)) {
			return 0;
		}
		int result = 0;
		unordered_map<string, int> dist;
		dist[beginWord] = 0;
		queue<string> q;
		q.push(beginWord);
		while (!q.empty()) {
			string s = q.front();
			q.pop();
			for (int n = s.size(), i = 0; i < n; ++i) {
				for (char ch = 'a'; ch <= 'z'; ++ch) {
					if (s[i] == ch) {
						continue;
					}
					string t(s);
					t[i] = ch;
					if (!words.count(t) or dist.count(t)) {
						continue;
					}
					dist[t] = dist[s] + 1;
					if (t == endWord) {
						return dist[t] + 1;
					}
					q.push(t);
				}
			}
		}
		return result;
	}
};