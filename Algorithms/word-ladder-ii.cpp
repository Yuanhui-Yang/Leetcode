// 126. Word Ladder II
// https://leetcode.com/problems/word-ladder-ii/

/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>> result;
		if (beginWord == endWord) {
			result.push_back(vector<string>({beginWord, endWord}));
			return result;
		}
		unordered_set<string> words(begin(wordList), end(wordList));
		if (!words.count(endWord)) {
			return result;
		}
		unordered_map<string, unordered_set<string>> rpath;
		int minDist = numeric_limits<int>::max();
		queue<string> q;
		q.push(beginWord);
		unordered_map<string, int> dist;
		dist[beginWord] = 0;
		while (!q.empty()) {
			string t = q.front();
			q.pop();
			if (dist[t] + 1 > minDist) {
				continue;
			}
			for (int n = t.size(), i = 0; i < n; ++i) {
				for (char ch = 'a'; ch <= 'z'; ++ch) {
					if (ch == t[i]) {
						continue;
					}
					string s(t);
					s[i] = ch;
					if (!words.count(s)) {
						continue;
					}
					if (!dist.count(s)) {
						dist[s] = 1 + dist[t];
						q.push(s);
						if (s == endWord) {
							minDist = dist[s];
						}
					}
					if (dist[s] > dist[t]) {
						rpath[s].insert(t);
					}
				}
			}
		}
		vector<string> v;
		f(rpath, result, v, endWord, beginWord);
		return result;
	}
private:
	void f(const unordered_map<string, unordered_set<string>> & rpath,
	vector<vector<string>> & result,
	vector<string> & v,
	const string & endWord,
	const string & beginWord) {
		v.insert(begin(v), endWord);
		if (endWord == beginWord) {
			result.push_back(v);
		}
		else if (rpath.count(endWord)) {
			const unordered_set<string> & s = rpath.at(endWord);
			for (const auto & i : s) {
				f(rpath, result, v, i, beginWord);
			}
		}
		v.erase(begin(v));
	}
};