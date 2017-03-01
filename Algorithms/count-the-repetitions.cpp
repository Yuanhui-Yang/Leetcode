// 466. Count The Repetitions
// https://leetcode.com/problems/count-the-repetitions/
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

// BEGIN: Time Limit Exceeded
class Solution {
public:
	int getMaxRepetitions(string s1, int n1, string s2, int n2) {
		if (s1.empty() || n1 <= 0 || s2.empty() || n2 <= 0) {
			return 0;
		}
		unordered_map<char, set<size_t>> dic_s1;
		for (size_t i = 0; i < s1.size(); i++) {
			const char ch = s1.at(i);
			dic_s1[ch].insert(i);
		}
		// vector<set<size_t>> vec_s2;
		// unordered_map<char, set<size_t>> dic_s2;
		for (size_t i = 0; i < s2.size(); i++) {
			const char ch = s2.at(i);
			if (!dic_s1.count(ch)) {
				return 0;
			}
			// dic_s2[ch].insert(i);
		}
		const size_t S1_size = s1.size() * size_t(n1);
		const size_t S2_size = s2.size() * size_t(n2);
		size_t i = 0;
		size_t j = 0;
		for (i = 0, j = 0; i < S1_size; j++) {
			const size_t jdx = j % s2.size();
			const char jch = s2.at(jdx);
			set<size_t>& dic_s1_set = dic_s1.at(jch);
			if (j == 0) {
				i = *begin(dic_s1_set);
				dic_s1_set.erase(begin(dic_s1_set));
				dic_s1_set.insert(i + s1.size());
				continue;
			}
			if (j > 0) {
				set<size_t>::iterator it = dic_s1_set.upper_bound(i);
				while (it == end(dic_s1_set)) {
					vector<size_t> tmp;
					for (const auto &k : dic_s1_set) {
						tmp.push_back(k + s1.size());
					}
					dic_s1_set.clear();
					dic_s1_set.insert(begin(tmp), end(tmp));
					it = dic_s1_set.upper_bound(i);
				}
				i = *it;
				vector<size_t> tmp(begin(dic_s1_set), next(it));
				dic_s1_set.erase(begin(dic_s1_set), next(it));
				for (const auto&k : tmp) {
					dic_s1_set.insert(k + s1.size());
				}
				continue;
			}
		}
		return (j - 1) / S2_size;
	}
};
// END: Time Limit Exceeded

int main(void) {
	Solution solution;
	string s1;
	int n1 = 0;
	string s2;
	int n2 = 0;
	int result = 0;
	int answer = 0;

	s1 = "abc";
	n1 = 1;
	s2 = "abc";
	n2 = 1;
	answer = 1;
	result = solution.getMaxRepetitions(s1, n1, s2, n2);
	assert(answer == result);

	s1 = "phqghumeaylnlfdxfircvscxggbwkfnqduxwfnfozvsrtkjpre";
	n1 = 1000000;
	s2 = "pggxr";
	n2 = 100;
	answer = 10000;
	result = solution.getMaxRepetitions(s1, n1, s2, n2);
	assert(answer == result);

	s1 = "phqghumeaylnlfdxfircvscxggbwkfnqduxwfnfozvsrtkjprepggxrpnrvystmwcysyycqpevikeffmznimkkasvwsrenzkycxf";
	n1 = 100;
	s2 = "xtlsgypsfa";
	n2 = 1;
	answer = 49;
	result = solution.getMaxRepetitions(s1, n1, s2, n2);
	assert(answer == result);

	s1 = "acb";
	n1 = 4;
	s2 = "ab";
	n2 = 2;
	answer = 2;
	result = solution.getMaxRepetitions(s1, n1, s2, n2);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}