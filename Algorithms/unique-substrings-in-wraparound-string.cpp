// 467. Unique Substrings in Wraparound String
// https://leetcode.com/problems/unique-substrings-in-wraparound-string/
#include <iostream>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
// BEGIN: http://bookshadow.com/weblog/2016/12/04/leetcode-unique-substrings-in-wraparound-string/
class Solution {
public:
	int findSubstringInWraproundString(string p) {
		if (p.empty()) return 0;
		const int n = p.size();
		vector<int> DICT(26, 0), OPT(n, 0);
		for (int i = 1; i < n; i++) {
			if ((p[i - 1] - 'a' + 1) % 26 == (p[i] - 'a')) {
				OPT[i] = OPT[i - 1];
			}
			else {
				OPT[i] = i;
			}
		}
		for (int i = 0; i < n; i++) {
			DICT[p[OPT[i]] - 'a'] = max(DICT[p[OPT[i]] - 'a'], i + 1 - OPT[i]);
		}
		for (int i = 0; i < 26; i++) {
			for (int j = 1; j < DICT[i]; j++) {
				int k = (i + j) % 26;
				DICT[k] = max(DICT[k], DICT[i] - j);
			}
		}
		return accumulate(begin(DICT), end(DICT), 0);
	}
};
// END: http://bookshadow.com/weblog/2016/12/04/leetcode-unique-substrings-in-wraparound-string/
// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	int findSubstringInWraproundString(string p) {
// 		if (p.empty()) return 0;
// 		const int n = p.size();
// 		vector<int> OPT(n, 0);
// 		unordered_set<string> hashset;
// 		hashset.insert(p.substr(0, 1));
// 		for (int i = 1; i < n; i++) {
// 			if ((p[i - 1] - 'a' + 1) % 26 == (p[i] - 'a')) {
// 				OPT[i] = OPT[i - 1];
// 				for (int j = OPT[i]; j <= i; j++) {
// 					hashset.insert(p.substr(j, i + 1 - j));
// 				}
// 			}
// 			else {
// 				OPT[i] = i;
// 				hashset.insert(p.substr(i, 1));
// 			}
// 		}
// 		return (int)hashset.size();
// 	}
// };
// END: Time Limit Exceeded
int main(void) {
	Solution solution;
	assert(0 == solution.findSubstringInWraproundString(""));
	assert(1 == solution.findSubstringInWraproundString("a"));
	assert(2 == solution.findSubstringInWraproundString("cac"));
	assert(6 == solution.findSubstringInWraproundString("zab"));
	assert(6 == solution.findSubstringInWraproundString("zaba"));
	assert(3 == solution.findSubstringInWraproundString("aabb"));
	assert(339 == solution.findSubstringInWraproundString("cdefghefghijklmnopqrstuvwxmnijklmnopqrstuvbcdefghijklmnopqrstuvwabcddefghijklfghijklmabcdefghijklmnopqrstuvwxymnopqrstuvwxyz"));
	assert(35503 == solution.findSubstringInWraproundString("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"));
	cout << "\nPassed All\n";
	return 0;
}