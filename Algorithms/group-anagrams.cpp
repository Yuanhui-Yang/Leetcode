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

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, list<int>> A;
		for (int sz = strs.size(), i = 0; i < sz; ++i) {
			string key(strs[i]);
			sort(begin(key), end(key));
			A[key].push_back(i);
		}
		vector<vector<string>> result(A.size());
		int depth = 0;
		for (const auto & i : A) {
			for (const auto & j : i.second) {
				result[depth].push_back(strs[j]);
			}
			++depth;
		}
		return result;
	}
};