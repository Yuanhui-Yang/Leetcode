// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/

/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> h;
		for (const auto &i : strs) {
			string j(i);
			sort(begin(j), end(j));
			h[j].push_back(i);
		}
		vector<vector<string>> result;
		for (const auto &i : h) {
			result.push_back(i.second);
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<string> strs;
	vector<vector<string>> answer, result;

	strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	answer = {{"ate", "eat","tea"}, {"nat","tan"}, {"bat"}};
	for (auto &i : answer) {
		sort(begin(i), end(i));
	}
	sort(begin(answer), end(answer));
	result = solution.groupAnagrams(strs);
	for (auto &i : result) {
		sort(begin(i), end(i));
	}
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}