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
		cout << i << '\t' << j << '\t';
		for (const auto &x : OPT) {
			cout << x << '\t';
		}
		cout << '\n';
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
			for (size_t m = 0; m < i; m++) {
				if (OPT[m] == OPT[i]) {
					OPT[i].clear();
					continue;
				}
			}
			if (helper(i + 1, pattern, j + OPT[i].size(), str, OPT)) {
				OPT[i].clear();
				return true;
			}
			OPT[i].clear();
		}
		return false;
	}
};
int main(void) {
	Solution solution;
	bool result;
	// result = solution.wordPatternMatch("ab", "aa");
	// assert(false == result);
	// result = solution.wordPatternMatch("abab", "redblueredblue");
	// assert(true == result);
	// result = solution.wordPatternMatch("aaaa", "asdasdasdasd");
	// assert(true == result);
	// result = solution.wordPatternMatch("aabb", "xyzabcxzyabc");
	// assert(false == result);
	result = solution.wordPatternMatch("itwasthebestoftimes", "ittwaastthhebesttoofttimes");
	assert(false == result);
	cout << "\nPassed All\n";
	return 0;
}