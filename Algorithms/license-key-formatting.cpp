// 482. License Key Formatting
// https://leetcode.com/problems/license-key-formatting/
#include <iostream>
#include <cassert>
#include <string>
using namespace std;
class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		string result;
		string x;
		for (const auto &i : S) {
			if (i != '-') {
				x.push_back(i);
			}
		}
		size_t y = x.size() % K;
		y = y ? y : K;
		for (size_t i = 0; i < y; i++) {
			char c = x[i];
			if (c >= 'a' && c <= 'z') {
				c += 'A' - 'a';
			}
			result.push_back(c);
		}
		for (size_t i = y; i < x.size(); i += K) {
			result.push_back('-');
			for (size_t j = 0; j < K; j++) {
				char c = x[i + j];
				if (c >= 'a' && c <= 'z') {
					c += 'A' - 'a';
				}
				result.push_back(c);
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	string result;
	result = solution.licenseKeyFormatting("2-4A0r7-4k", 4);
	assert("24A0-R74K" == result);
	result = solution.licenseKeyFormatting("2-4A0r7-4k", 3);
	assert("24-A0R-74K" == result);
	cout << "\nPassed All\n";
	return 0;
}