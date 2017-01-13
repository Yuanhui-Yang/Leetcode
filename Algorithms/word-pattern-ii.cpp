// 291. Word Pattern II
// https://leetcode.com/problems/word-pattern-ii/
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	bool wordPatternMatch(string pattern, string str) {
		vector<string> OPT(pattern.size());
		return helper(0, pattern, 0, str, OPT);
	}
private:
	bool helper(size_t i, string pattern, size_t j, string str, vector<string>& OPT) {
		if (i == pattern.size() && j == str.size()) {
			return true;
		}
		if (i >= pattern.size() || j >= str.size()) {
			return false;
		}
		size_t k = 0;
		while (k < i && pattern[k] != pattern[i]) k++;
		if (k < i) {
			if (j + OPT[k].size() > str.size()) {
				return false;
			}
			if (str.substr(j, OPT[k].size()) != OPT[k]) {
				return false;
			}
			OPT[i] = OPT[k];
			if (helper(i + 1, pattern, j + OPT[k].size(), str, OPT)) {
				OPT[i].clear();
				return true;
			}
			OPT[i].clear();
			return false;
		}
		for (size_t l = j + 1; l <= str.size(); l++) {
			OPT[i] = str.substr(j, l - j);
			if (!isUnique(i, OPT[i], OPT)) {
				OPT[i].clear();
				continue;
			}
			if (helper(i + 1, pattern, l, str, OPT)) {
				OPT[i].clear();
				return true;
			}
			OPT[i].clear();
		}
		return false;
	}
private:
	bool isUnique(size_t j, string str, vector<string>& OPT) {
		for (size_t i = 0; i < j; i++) {
			if (OPT[i] == str) {
				return false;
			}
		}
		return true;
	}
};
int main(void) {
	Solution solution;
	bool result;
	result = solution.wordPatternMatch("ab", "aa");
	assert(false == result);
	result = solution.wordPatternMatch("abab", "redblueredblue");
	assert(true == result);
	result = solution.wordPatternMatch("aaaa", "asdasdasdasd");
	assert(true == result);
	result = solution.wordPatternMatch("aabb", "xyzabcxzyabc");
	assert(false == result);
	result = solution.wordPatternMatch("itwasthebestoftimes", "ittwaastthhebesttoofttimes");
	assert(true == result);
	result = solution.wordPatternMatch("itwasthebestoftimes", "ittwaastthhebesttoofttimesss");
	assert(false == result);
	cout << "\nPassed All\n";
	return 0;
}