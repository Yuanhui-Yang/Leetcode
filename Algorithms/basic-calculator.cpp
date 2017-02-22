// 224. Basic Calculator
// https://leetcode.com/problems/basic-calculator/
#include <iostream>
#include <cassert>
#include <string>
using namespace std;
class Solution {
public:
	int calculate(string s) {
		return 0;
	}
};
int main(void) {
	Solution solution;
	string s;
	int result = 0;
	int answer = 0;

	s = "1 + 1";
	answer = 2;
	result = solution.calculate(s);
	assert(answer == result);

	s = " 2-1 + 2 ";
	answer = 3;
	result = solution.calculate(s);
	assert(answer == result);

	s = "(1+(4+5+2)-3)+(6+8)";
	answer = 23;
	result = solution.calculate(s);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}