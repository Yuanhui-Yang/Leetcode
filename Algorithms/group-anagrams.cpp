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
        unordered_map<size_t, vector<string>> A;
        for (const auto & str : strs) {
            A[f2(str)].push_back(str);
        }
        vector<vector<string>> result;
        for (const auto & i : A) {
            result.push_back(i.second);
        }
        return result;
    }
private:
    string f1(const string & str) {
        string result;
        array<int, 26> A;
        A.fill(26);
        for (const auto & ch : str) {
            int id = ch - 'a';
            ++A[id];
        }
        for (int i = 0; i < 26; ++i) {
            result.append(to_string(A[i]));
            result.push_back('#');
        }
        return result;
    }
    size_t f2(const string & str) {
        array<size_t, 26> A = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
        size_t result = 1;
        for (const auto & ch : str) {
            int id = ch - 'a';
            result *= A[id];
        }
        return result;
    }
};

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
