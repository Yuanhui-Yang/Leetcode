// 131. Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning/

/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/

class Solution {
public:
	vector<vector<string>> partition(string s) {
		return f(s, s.size(), 0);
	}
private:
	vector<vector<string>> f(const string& s, int n, int i) {
		if (i >= n) {
			return {};
		}
		vector<vector<string>> result;
		for (int j = i; j < n; ++j) {
			if (g(s, i, j)) {
				string t = s.substr(i, j + 1 - i);
				vector<vector<string>> m = f(s, n, j + 1);
				if (m.empty()) {
					result.push_back({t});
				}
				else {
					for (auto &i : m) {
						i.insert(begin(i), t);
						result.push_back(i);
					}
				}                
			}
		}
		return result;
	}
	bool g(const string & s, int i, int j) {
		while (i < j) {
			if (s[i] == s[j]) {
				++i;
				--j;
				continue;
			}
			return false;
		}
		return true;
	}
};