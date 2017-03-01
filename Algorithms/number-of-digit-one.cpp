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
			for (size_t k = 0; k <= len - 1; k++) {
				result += (k + 1) * C[len - 1][k] * pow(9, len - k - 1);
			}
			for (size_t k = 1; k <= len - 1; k++) {
				result += 8 * k * C[len - 1][k] * pow(9, len - k - 1);
			}
		}
		return result += countDigitOne(0, to_string_n_size, to_string_n, C);
	}
private:
	size_t countDigitOne(size_t base, const size_t to_string_n_size, string N, const vector<vector<size_t>>& C) {
		if (N.empty()) {
			return base;
		}
		if (N.front() == '0') {
			return countDigitOne(base, to_string_n_size, N.substr(1), C);
		}
		if (N.front() == '1') {
			if (to_string_n_size == N.size()) {
				return countDigitOne(base + 1, to_string_n_size, N.substr(1), C);
			}
			size_t result = 0;
			for (size_t k = 0; k <= N.size() - 1; k++) {
				result += (k + base) * C[N.size() - 1][k] * pow(9, N.size() - k - 1);
			}
			return result += countDigitOne(base + 1, to_string_n_size, N.substr(1), C);
		}
		size_t result = 0;
		if (to_string_n_size == N.size()) {
			result = 0;
			for (size_t k = 1; k <= N.size(); k++) {
				result += k * C[N.size() - 1][k - 1] * pow(9, N.size() - k);
			}
			for (size_t k = 1; k <= N.size() - 1; k++) {
				result += k * (N.front() - '2') * C[N.size() - 1][k] * pow(9, N.size() - k - 1);
			}
			return result += countDigitOne(base, to_string_n_size, N.substr(1), C);
		}
		result = 0;
		for (size_t k = 0; k <= N.size() -  1; k++) {
			result += (k + base + 1) * C[N.size() - 1][k] * pow(9, N.size() - k - 1);
		}
		for (size_t k = 0; k <= N.size() - 1; k++) {
			result += (k + base) * (N.front() - '1') * C[N.size() - 1][k] * pow(9, N.size() - k - 1);
		}
		return result += countDigitOne(base, to_string_n_size, N.substr(1), C);
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

	n = 110;
	answer = 33;
	result = solution.countDigitOne(n);
	// cout << "result = " << result << '\n';
	assert(answer == result);

	n = 100;
	answer = 21;
	result = solution.countDigitOne(n);
	// cout << "result = " << result << '\n';
	assert(answer == result);

	n = 11;
	answer = 4;
	result = solution.countDigitOne(n);
	// cout << "result = " << result << '\n';
	assert(answer == result);

	n = 824883294;
	answer = 767944060;
	result = solution.countDigitOne(n);
	// cout << "result = " << result << '\n';
	assert(answer == result);

	n = 13;
	answer = 6;
	result = solution.countDigitOne(n);
	// cout << "result = " << result << '\n';
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
