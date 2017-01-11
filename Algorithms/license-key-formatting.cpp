// 482. License Key Formatting
// https://leetcode.com/problems/license-key-formatting/
#include <iostream>
#include <cassert>
#include <string>
using namespace std;
class Solution {
public:
	string licenseKeyFormatting(string S, int K) {

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