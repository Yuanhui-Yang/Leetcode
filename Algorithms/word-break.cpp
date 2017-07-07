// 139. Word Break
// https://leetcode.com/problems/word-break/

/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		if (s.empty() or wordDict.empty()) {
			return false;
		}
		int n = s.size();
		unordered_set<string> h(begin(wordDict), end(wordDict));
		vector<bool> vec(n + 1, false);
		vec[0] = true;
		for (int j = 1; j <= n; ++j) {
			for (int i = 0; i < j and !vec[j]; ++i) {
				vec[j] = vec[j] or (vec[i] and h.count(s.substr(i, j - i)));
			}
		}
		return vec[n];
	}
};