// 524. Longest Word in Dictionary through Deleting
// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		string result;
		unordered_map<char, set<size_t>> hash_map;
		for (size_t i = 0; i < s.size(); i++) {
			hash_map[s.at(i)].insert(i);
		}
		for (const auto &i : d) {
			if (validate(i, hash_map)) {
				if (result.empty()) {
					result = i;
					continue;
				}
				if (i.size() > result.size()) {
					result = i;
					continue;
				}
				if (i.size() == result.size()) {
					result = min(result, i);
					continue;
				}
			}
		}
		return result;
	}
private:
	bool validate(const string& s, const unordered_map<char, set<size_t>>& hash_map) {
		for (size_t i = 0, j = 0; i < s.size(); i++) {
			const char ch = s.at(i);
			if (!hash_map.count(ch)) {
				return false;
			}
			const set<size_t>& rbtree = hash_map.at(ch);
			if (i == 0) {
				j = *begin(rbtree);
				continue;
			}
			if (i > 0) {
				if (rbtree.upper_bound(j) == end(rbtree)) {
					return false;
				}
				j = *(rbtree.upper_bound(j));
				continue;
			}
		}
		return true;
	}
};
int main(void) {
	Solution solution;
	string s;
	vector<string> d;
	string result;
	string answer;

	s = "abpcplea";
	d = {"ale", "apple", "monkey", "plea"};
	answer = "apple";
	result = solution.findLongestWord(s, d);
	assert(answer == result);

	s = "abpcplea";
	d = {"a", "b", "c"};
	answer = "a";
	result = solution.findLongestWord(s, d);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}