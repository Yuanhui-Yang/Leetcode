// 504. Base 7
// https://leetcode.com/problems/base-7/
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	string convertToBase7(int num) {
		if (!num) {
			return "0";
		}
		bool negative = num < 0;
		string result;
		if (negative) {
			num = -num;
		}
		while (num > 0) {
			result.push_back(char(num % 7 + '0'));
			num /= 7;
		}
		if (negative) {
			result.push_back('-');
		}
		reverse(begin(result), end(result));
		return result;
	}
};
int main(void) {
	Solution solution;
	int num = 0;
	string result;
	string answer;

	num = 100;
	result = solution.convertToBase7(num);
	answer = "202";
	assert(answer == result);

	num = -7;
	result = solution.convertToBase7(num);
	answer = "-10";
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}