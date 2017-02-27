// 233. Number of Digit One
// https://leetcode.com/problems/number-of-digit-one/
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int countDigitOne(int n) {

	}
};

// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	int countDigitOne(int n) {
// 		size_t result = 0;
// 		for (int i = 1; i <= n; i++) {
// 			string s = to_string(i);
// 			for (const auto &j : s) {
// 				result += j == '1';
// 			}
// 		}
// 		return result;
// 	}
// };
// END: Time Limit Exceeded
int main(void) {
	Solution solution;
	int n = 0;
	int result = 0;
	int answer = 0;

	n = 824883294;
	answer = 767944060;
	result = solution.countDigitOne(n);
	assert(answer == result);

	n = 13;
	answer = 6;
	result = solution.countDigitOne(n);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
