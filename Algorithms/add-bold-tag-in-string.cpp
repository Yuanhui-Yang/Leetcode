// 616. Add Bold Tag in String
// https://leetcode.com/problems/add-bold-tag-in-string/

/*
Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.

Example 1:
Input: 
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"
Example 2:
Input: 
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"
Note:
The given dict won't contain duplicates, and its length won't exceed 100.
All the strings in input have length in range [1, 1000].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string addBoldTag(string s, vector<string>& dict) {
		vector<pair<int, int>> u, v;
		for (const auto &t : dict) {
			vector<pair<int, int>> w = f(s, t);
			u.insert(end(u), begin(w), end(w));
		}
		sort(begin(u), end(u));
		for (int n = u.size(), i = 0; i < n; ++i) {
			pair<int, int> &p = u[i];
			int x = p.first, y = p.second;
			while (i + 1 < n and u[i + 1].first <= y) {
				y = max(y, u[++i].second);
			}
			v.push_back({x, y});
		}
		if (v.empty()) {
			return s;
		}
		string result;
		result += s.substr(0, v.front().first);
		for (int n = v.size(), i = 0; i < n; ++i) {
			result += "<b>" + s.substr(v[i].first, v[i].second - v[i].first) + "</b>";
			if (i + 1 < n) {
				result += s.substr(v[i].second, v[i + 1].first - v[i].second);
			}
		}
		result += s.substr(v.back().second);
		return result;
	}
private:
	vector<pair<int, int>> f(const string& s, const string& t) {
		int m = s.size(), n = t.size(), i = 0, j = -1;
		vector<int> next(n + 1);
		next.front() = -1;
		while (i < n) {
			if (j == -1 or t[i] == t[j]) {
				next[++i] = ++j;
			}
			else {
				j = next[j];
			}
		}
		i = 0;
		j = 0;
		vector<pair<int, int>> result;
		while (i < m) {
			if (j == -1 or s[i] == t[j]) {
				++i;
				++j;
			}
			else {
				j = next[j];
			}
			if (j == n) {
				result.push_back({i - n, i});
				i -= n - 1;
				j = 0;
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	string s, answer, result;
	vector<string> dict;

	s = "qrzjsorbkmyzzzvoqxefvxkcwtpkhzbakuufbpgdkykmojwuennrjeciqvvacpzrrczfhxnsmginzwinzihpomxtmweyyzzmgcoiupjnidphvzlnxtcogufozlenjfvokztghwckzyvmktduqkizixzxpanjwrdeudjyftxksjgdklwxrhmudhrtemuvelykqaafzlqmennttkighcdxfozdcoqkyshhajipnsdrljrnlwmyjuwxsebpqm";
	dict = {"qr", "zj", "so", "rb", "km", "yz", "zz", "vo", "qx", "ef", "vx", "kc", "wt", "pk"};
	answer = "<b>qrzjsorbkmyzzzvoqxefvxkcwtpk</b>hzbakuufbpgdky<b>km</b>ojwuennrjeciqvvacpzrrczfhxnsmginzwinzihpomxtmwey<b>yzz</b>mgcoiupjnidphvzlnxtcogufozlenjf<b>vo</b>kztghwckzyvmktduqkizixzxpanjwrdeudjyftxksjgdklwxrhmudhrtemuvelykqaafzlqmennttkighcdxfozdcoqkyshhajipnsdrljrnlwmyjuwxsebpqm";
	result = solution.addBoldTag(s, dict);
	assert(answer == result);

	s = "abcxyz123";
	dict = {"abc", "123"};
	answer = "<b>abc</b>xyz<b>123</b>";
	result = solution.addBoldTag(s, dict);
	assert(answer == result);

	s = "aaabbcc";
	dict = {"aaa", "aab", "bc"};
	answer = "<b>aaabbc</b>c";
	result = solution.addBoldTag(s, dict);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}