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
			result.push_back({beginWord, endWord});
			return result;
		}
		unordered_map<string, unordered_set<string>> rpath;
		unordered_set<string> words(begin(wordList), end(wordList));
		if (!words.count(endWord)) {
			return result;
		}
		int shortest = numeric_limits<int>::max();
		unordered_map<string, int> dist;
		dist[beginWord] = 0;
		queue<string> q;
		q.push(beginWord);
		while (!q.empty()) {
			string s = q.front();
			q.pop();
			if (dist[s] > shortest) {
			break;
			}
			for (int n = s.size(), i = 0; i < n; ++i) {
				for (char ch = 'a'; ch <= 'z'; ++ch) {
					if (s[i] == ch) {
						continue;
					}
					string t(s);
					t[i] = ch;
					if (!words.count(t)) {
						continue;
					}
					if (!dist.count(t)) {
						dist[t] = dist[s] + 1;
						q.push(t);
						if (t == endWord) {
							shortest = dist[t];
						}
					}
					if (dist[t] > dist[s]) {
						rpath[t].insert(s);
					}
				}
			}
		}
		vector<string> v;
		f(result, v, rpath, endWord, beginWord);
		return result;
	}
private:
	void f(vector<vector<string>> & result, vector<string> & v, const unordered_map<string, unordered_set<string>> & rpath, const string & endWord, const string & beginWord) {
		v.insert(begin(v), endWord);
		if (endWord == beginWord) {
			result.push_back(v);
		}
		else if (rpath.count(endWord)) {
			for (const auto & i : rpath.at(endWord)) {
				f(result, v, rpath, i, beginWord);
			}
		}
		v.erase(begin(v));
	}
};

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>> result;
		if (beginWord == endWord) {
			result.push_back(vector<string>({beginWord, endWord}));
			return result;
		}
		unordered_set<string> words(begin(wordList), end(wordList));
		unordered_map<string, unordered_set<string>> rpath;
		list<string> current({beginWord});
		bool flag = true;
		while (!current.empty() and flag) {
			for (const auto & s : current) {
				if (words.count(s)) {
					words.erase(s);
				}
			}
			list<string> next;
			for (const auto & s : current) {
				for (int n = s.size(), i = 0; i < n; ++i) {
					for (char ch = 'a'; ch <= 'z'; ++ch) {
						if (s[i] == ch) {
							continue;
						}
						string t(s);
						t[i] = ch;
						if (!words.count(t)) {
							continue;
						}
						rpath[t].insert(s);
						next.push_back(t);
						if (t == endWord) {
							flag = false;
						}
					}
				}
			}
			current = next;
		}
		vector<string> v;
		f(result, v, rpath, endWord, beginWord);
		return result;
	}
private:
	void f(vector<vector<string>> & result, vector<string> & v, const unordered_map<string, unordered_set<string>> & rpath, const string & endWord, const string & beginWord) {
		v.insert(begin(v), endWord);
		if (endWord == beginWord) {
			result.push_back(v);
		}
		else if (rpath.count(endWord)) {
			for (const auto & i : rpath.at(endWord)) {
				f(result, v, rpath, i, beginWord);
			}
		}
		v.erase(begin(v));
	}
};