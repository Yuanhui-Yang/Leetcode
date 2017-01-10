// 471. Encode String with Shortest Length
// https://leetcode.com/problems/encode-string-with-shortest-length/
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/71541/easy-to-understand-c-o-n-3-solution
class Solution {
public:
	string encode(string s) {
		if (s.size() < 5) return s;
		vector<vector<string>> OPT(s.size(), vector<string>(s.size()));
		for (size_t len = 1; len <= s.size(); len++) {
			for (size_t i = 0; i + len <= s.size(); i++) {
				size_t j = i + len - 1;
				const string s_substr = s.substr(i, len);
				OPT[i][j] = s_substr;
				if (len >= 5) {
					const string s_collapse = collapse(s, i, j, OPT);
					OPT[i][j] = s_collapse.size() < OPT[i][j].size() ? s_collapse : OPT[i][j];
					for (size_t l = 1; l < len; l++) {
						const string s_replace = OPT[i][i + l - 1] + OPT[i + l][j];
						OPT[i][j] = s_replace.size() < OPT[i][j].size() ? s_replace : OPT[i][j];
					}
				}
			}
		}
		return OPT[0][s.size() - 1];
	}
private:
	string collapse(const string& s, const size_t i, const size_t j, const vector<vector<string>>& OPT) {
		const string s_substr = s.substr(i, j - i + 1);
		size_t pos = (s_substr + s_substr).find(s_substr, 1);
		return to_string(s_substr.size() / pos) + '[' + OPT[i][i + pos - 1] + ']';
	}
};
// END: https://discuss.leetcode.com/topic/71541/easy-to-understand-c-o-n-3-solution
int main(void) {
	Solution solution;
	string result;
	result = solution.encode("aaa");
	assert(unordered_set<string>({"aaa"}).count(result));
	result = solution.encode("aaaaa");
	assert(unordered_set<string>({"5[a]"}).count(result));
	result = solution.encode("aaaaaaaaaa");
	assert(unordered_set<string>({"10[a]", "a9[a]", "9[a]a"}).count(result));
	result = solution.encode("aabcaabcd");
	assert(unordered_set<string>({"2[aabc]d"}).count(result));
	result = solution.encode("abbbabbbcabbbabbbc");
	assert(unordered_set<string>({"2[2[abbb]c]"}).count(result));
	cout << "\nPassed All\n";
	return 0;
}
