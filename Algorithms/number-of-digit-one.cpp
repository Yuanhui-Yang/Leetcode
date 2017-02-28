// 233. Number of Digit One
// https://leetcode.com/problems/number-of-digit-one/
#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		if (n <= 0) {
			return 0;
		}
		if (n <= 9) {
			return 1;
		}
		const string to_string_n = to_string(n);
		const size_t to_string_n_size = to_string_n.size();
		vector<vector<size_t>> C(to_string_n_size, vector<size_t>(to_string_n_size, 1));
		for (size_t i = 2; i < to_string_n_size; i++) {
			for (size_t j = 1; j < i; j++) {
				C[i][j] = C[i][j - 1] * (i + 1 - j) / j;
				// cout << "C_" << i << "^" << j << " = " << C[i][j] << '\t';
			}
			// cout << '\n';
		}
		size_t result = 1;
		for (size_t len = 2; len < to_string_n_size; len++) {
			for (size_t k = 1; k <= len; k++) {
				result += k * C[len - 1][k - 1] * pow(9, len - k);
			}
			for (size_t k = 1; k <= len - 1; k++) {
				result += 8 * k * C[len - 1][k] * pow(9, len - k);
			}
		}
		return result += countDigitOne(0, to_string_n_size, to_string_n);
	}
private:
	size_t countDigitOne(size_t base, const size_t to_string_n_size, string N) {
		if (N.empty()) {
			return 1;
		}
		if (N.front() == '0') {
			return countDigitOne(base, to_string_n_size, N.substr(1));
		}
		if (N.front() == '1') {
			if (!base) {
				return countDigitOne(base + 1, to_string_n_size, N.substr(1));
			}
			return countDigitOne(base, to_string_n_size, N.substr(1)) + countDigitOne(base + 1, to_string_n_size, N.substr(1));
		}
		size_t result = 0;
		if (to_string_n_size == N.size()) {

		}

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
