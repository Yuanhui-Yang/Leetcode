// 316. Remove Duplicate Letters
// https://leetcode.com/problems/remove-duplicate-letters/
#include <iostream>
#include <cassert>
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
	string removeDuplicateLetters(string s) {
		if (s.empty()) {
			return "";
		}
		map<char, set<size_t>> tree_map;
		for (size_t i = 0; i < s.size(); i++) {
			tree_map[s.at(i)].insert(i);
		}
		string result;
		while (!tree_map.empty()) {
			for (map<char, set<size_t>>::iterator it = begin(tree_map);
				it != end(tree_map);
				it++) {
				if (validate(it, tree_map)) {
					result.push_back(it->first);
					tree_map.erase(it);
					break;
				}
			}
		}
		return result;
	}
private:
	bool validate(map<char, set<size_t>>::iterator it, map<char, set<size_t>>& tree_map) {
			for (map<char, set<size_t>>::iterator jt = begin(tree_map);
				jt != end(tree_map);
				jt++) {
				if (jt != it && jt->second.upper_bound(*begin(it->second)) == end(jt->second)) {
					return false;
				}
			}
			for (map<char, set<size_t>>::iterator jt = begin(tree_map);
				jt != end(tree_map);
				jt++) {
				if (jt != it) {
					jt->second.erase(begin(jt->second), jt->second.upper_bound(*begin(it->second)));
				}
			}
			return true;
	}
};
int main(void) {
	Solution solution;
	string s;
	string result;
	string answer;

	s = "bbcaac";
	answer = "bac";
	result = solution.removeDuplicateLetters(s);
	assert(answer == result);

	s = "bcabc";
	answer = "abc";
	result = solution.removeDuplicateLetters(s);
	assert(answer == result);

	s = "cbacdcbc";
	answer = "acdb";
	result = solution.removeDuplicateLetters(s);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
