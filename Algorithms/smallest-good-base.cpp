// 483. Smallest Good Base
// https://leetcode.com/problems/smallest-good-base/
#include <iostream>
#include <cctype>
#include <cassert>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
	string smallestGoodBase(string n) {

	}
};

// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	string smallestGoodBase(string n) {
// 		const size_t val = stoull(n);
// 		for (size_t k = 2; k < val; k++) {
// 			if (validate(k, val)) {
// 				return to_string(k);
// 			}
// 		}
// 		return "";
// 	}
// private:
// 	bool validate(const size_t k, size_t val) {
// 		while (val > 1) {
// 			if ((val % k) != 1) {
// 				return false;
// 			}
// 			val /= k;
// 		}
// 		return val == 1;
// 	}
// };
// END: Time Limit Exceeded

int main(void) {
	Solution solution;
	string n;
	string result;
	string answer;

	n = "13";
	answer = "686286299";
	result = solution.smallestGoodBase(n);
	assert(answer == result);

	n = "4681";
	answer = "8";
	result = solution.smallestGoodBase(n);
	assert(answer == result);

	n = "1000000000000000000";
	answer = "999999999999999999";
	result = solution.smallestGoodBase(n);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}