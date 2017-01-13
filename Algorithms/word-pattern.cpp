// 290. Word Pattern
// https://leetcode.com/problems/word-pattern/
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		vector<string> str_vec;
		for (size_t i = 0, j = 0; i < str.size(); i++) {
			if (i + 1 == str.size() || str[i] == ' ') {
				string s = i + 1 == str.size() ? str.substr(j, str.size() - j) : str.substr(j, i - j);
				str_vec.push_back(s);
				j = i + 1;
			}
		}
		if (pattern.size() != str_vec.size()) {
			return false;
		}
		unordered_map<char, vector<size_t>> pattern_hashmap;
		unordered_map<string, vector<size_t>> str_hashmap;
		for (size_t i = 0; i < pattern.size(); i++) {
			pattern_hashmap[pattern[i]].push_back(i);
			str_hashmap[str_vec[i]].push_back(i);
		}
		for (size_t i = 0; i < pattern.size(); i++) {
			if (pattern_hashmap[pattern[i]] != str_hashmap[str_vec[i]]) {
				return false;
			}
		}
		return true;
	}
};
int main(void) {
	Solution solution;
	bool result;
	result = solution.wordPattern("abba", "dog cat cat dog");
	assert(true == result);
	result = solution.wordPattern("abba", "dog cat cat fish");
	assert(false == result);
	result = solution.wordPattern("aaaa", "dog cat cat dog");
	assert(false == result);
	result = solution.wordPattern("abba", "dog dog dog dog");
	assert(false == result);
	cout << "\nPassed All\n";
	return 0;
}