// 140. Word Break II
// https://leetcode.com/problems/word-break-ii/

/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/

class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		int n = s.size();
		unordered_set<string> h(begin(wordDict), end(wordDict));
		vector<bool> vec(n + 1, false);
		vec[0] = true;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < i and !vec[i]; ++j) {
				vec[i] = vec[i] or (vec[j] and h.count(s.substr(j, i - j)));
			}
		}
		if (!vec[n]) {
			return {};
		}
		vector<vector<string>> mat(n + 1);
		mat[0] = {""};
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < i; ++j) {
				string b(s.substr(j, i - j));
				if (h.count(b)) {
					for (const auto & a : mat[j]) {
						mat[i].push_back(a == "" ? b : a + " " + b);
					}
				}
			}
		}
		return mat[n];
	}
};