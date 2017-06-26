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
		int n = s.size();
		vector<int> M(n, -1);
		return f(M, s, 0, n);
	}
private:
	int f(vector<int>& M, const string& s, int i, int n) {
		if (i >= n) {
			return M[i] = 1;
		}
		if (M[i] >= 0) {
			return M[i];
		}
		if (i + 1 >= n) {
			return M[i] = s[i] >= '1';
		}
		bool x = s[i] >= '1', y = s[i] == '1' or (s[i] == '2' and s[i + 1] <= '6');
		return M[i] = x ? f(M, s, i + 1, n) + (y ? f(M, s, i + 2, n) : 0) : 0;
	}
};

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