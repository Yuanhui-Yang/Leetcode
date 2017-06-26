// 91. Decode Ways
// https://leetcode.com/problems/decode-ways/

/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty()) {
			return 0;
		}
		int n = s.size(), x = s.back() >= '1', y = 1;
		for (int i = n - 2; i >= 0; --i) {
			if (s[i] == '0') {
				y = x;
				x = 0;
				continue;
			}
			bool z = s[i] == '1' or (s[i] == '2' and s[i + 1] <= '6');
			int t = x;
			x += z ? y : 0;
			y = t;
		}
		return x;
	}
};

// class Solution {
// public:
// 	int numDecodings(string s) {
// 		if (s.empty()) {
// 			return 0;
// 		}
// 		int n = s.size();
// 		vector<int> M(n + 1, 0);
// 		M.back() = 1;
// 		for (int i = n - 1; i >= 0; --i) {
// 			if (s[i] == '0') {
// 				M[i] = 0;
// 				continue;
// 			}
// 			if (i + 1 == n) {
// 				M[i] = s[i] >= '1';
// 				continue;
// 			}
// 			bool x = s[i] == '1' or (s[i] == '2' and s[i + 1] <= '6');
// 			M[i] = M[i + 1] + (x ? M[i + 2] : 0);
// 		}
// 		return M.front();
// 	}
// };

int main(void) {
	Solution solution;
	string s;
	int answer, result;

	s = "";
	answer = 0;
	result = solution.numDecodings(s);
	assert(answer == result);

	s = "12";
	answer = 2;
	result = solution.numDecodings(s);
	assert(answer == result);

	s = "27";
	answer = 1;
	result = solution.numDecodings(s);

	s = "00";
	answer = 0;
	result = solution.numDecodings(s);
	assert(answer == result);

	s = "01";
	answer = 0;
	result = solution.numDecodings(s);
	assert(answer == result);

	s = "012";
	answer = 0;
	result = solution.numDecodings(s);
	assert(answer == result);

	s = "111";
	answer = 3;
	result = solution.numDecodings(s);
	assert(answer == result);

	s = "230";
	answer = 0;
	result = solution.numDecodings(s);
	assert(answer == result);

	s = "6065812287883668764831544958683283296479682877898293612168136334983851946827579555449329483852397155";
	answer = 0;
	result = solution.numDecodings(s);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}