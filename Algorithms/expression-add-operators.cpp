// 282. Expression Add Operators
// https://leetcode.com/problems/expression-add-operators/
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<string> addOperators(string num, int target) {
		if (num.empty()) {
			return {};
		}
		vector<string> result;
		addOperators("", "", 0, (long long)target, num, result);
		return result;
	}
private:
	void addOperators(const string solution,
		const string multiple_str,
		const long long multiple_val,
		const long long target,
		const string num,
		vector<string>& result) {
		if (num.empty()) {
			if (target == 0) {
				result.push_back(solution);
			}
			return;
		}
		if (num.front() == '0') {
			if (multiple_str.empty()) {
				if (num.size() == 1) {
					if (solution.empty()) {
						addOperators("0", "", 0, target, "", result);
					}
					else {
						addOperators(solution + "+0", "", 0, target, "", result);
						addOperators(solution + "-0", "", 0, target, "", result);
					}
					return;
				}
				if (num.size() >= 2) {
					if (solution.empty()) {
						addOperators("0", "", 0, target, num.substr(1), result);
					}
					else {
						addOperators(solution + "+0", "", 0, target, num.substr(1), result);
						addOperators(solution + "-0", "", 0, target, num.substr(1), result);
					}
					addOperators(solution, "0", 0, target, num.substr(1), result);
					return;
				}
				return;
			}
			if (!multiple_str.empty()) {
				if (num.size() == 1) {
					if (solution.empty()) {
						addOperators(multiple_str + "*0", "", 0, target, "", result);
					}
					else {
						addOperators(solution + "+" + multiple_str + "*0", "", 0, target, "", result);
						addOperators(solution + "-" + multiple_str + "*0", "", 0, target, "", result);
					}
					return;
				}
				if (num.size() >= 2) {
					if (solution.empty()) {
						addOperators(multiple_str + "*0", "", 0, target, num.substr(1), result);
					}
					else {
						addOperators(solution + "+" + multiple_str + "*0", "", 0, target, num.substr(1), result);
						addOperators(solution + "-" + multiple_str + "*0", "", 0, target, num.substr(1), result);
					}
					addOperators(solution, multiple_str + "*0", 0, target, num.substr(1), result);
					return;
				}
				return;
			}
			return;
		}
		if (num.front() != '0') {
			if (multiple_str.empty()) {
				for (size_t len = 1; len < num.size(); len++) {
					const string left_str = num.substr(0, len);
					const long long stoll_left_str = stoll(left_str);
					const string right_str = num.substr(len);
					if (solution.empty()) {
						addOperators(left_str, "", 0, target - stoll_left_str, right_str, result);
					}
					else {
						addOperators(solution + "+" + left_str, "", 0, target - stoll_left_str, right_str, result);
						addOperators(solution + "-" + left_str, "", 0, target + stoll_left_str, right_str, result);
					}
					addOperators(solution, left_str, stoll_left_str, target, right_str, result);
				}
				const long long stoll_num = stoll(num);
				if (solution.empty()) {
					addOperators(num, "", 0, target - stoll_num, "", result);
				}
				else {
					addOperators(solution + "+" + num, "", 0, target - stoll_num, "", result);
					addOperators(solution + "-" + num, "", 0, target + stoll_num, "", result);
				}
				return;
			}
			if (!multiple_str.empty()) {
				for (size_t len = 1; len < num.size(); len++) {
					const string left_str = num.substr(0, len);
					const long long stoll_left_str = stoll(left_str);
					const string right_str = num.substr(len);
					if (solution.empty()) {
						addOperators(multiple_str + "*" + left_str, "", 0, target - multiple_val * stoll_left_str, right_str, result);
					}
					else {
						addOperators(solution + "+" + multiple_str + "*" + left_str, "", 0, target - multiple_val * stoll_left_str, right_str, result);
						addOperators(solution + "-" + multiple_str + "*" + left_str, "", 0, target + multiple_val * stoll_left_str, right_str, result);
					}
					addOperators(solution, multiple_str + "*" + left_str, multiple_val * stoll_left_str, target, right_str, result);
				}
				const long long stoll_num = stoll(num);
				if (solution.empty()) {
					addOperators(multiple_str + "*" + num, "", 0, target - multiple_val * stoll_num, "", result);
				}
				else {
					addOperators(solution + "+" + multiple_str + "*" + num, "", 0, target - multiple_val * stoll_num, "", result);
					addOperators(solution + "-" + multiple_str + "*" + num, "", 0, target + multiple_val * stoll_num, "", result);
				}
				return;
			}
			return;
		}
		return;
	}
};
int main(void) {
	Solution solution;
	string num;
	int target = 0;
	vector<string> result;
	vector<string> answer;
	vector<string> difference;
	vector<string>::iterator it;

	num = "000";
	target = 0;
	answer = {"0*0*0", "0*0+0", "0*0-0", "0+0*0", "0+0+0", "0+0-0", "0-0*0", "0-0+0", "0-0-0"};
	result = solution.addOperators(num, target);
	difference.clear();
	difference.resize(result.size());
	sort(begin(result), end(result));
	sort(begin(answer), end(answer));
	it = set_difference(begin(result), end(result), begin(answer), end(answer), begin(difference));
	difference.resize(distance(begin(difference), it));
	assert(answer == result);

	num = "123456789";
	target = 45;
	answer = {"1*2*3*4*5-6-78+9", "1*2*3*4+5+6-7+8+9", "1*2*3+4+5+6+7+8+9", "1*2*3+4+5-6*7+8*9", "1*2*3+4-5*6+7*8+9", "1*2*3+4-5*6-7+8*9", "1*2*3-4*5+6*7+8+9", "1*2*3-4*5-6+7*8+9", "1*2*3-4*5-6-7+8*9", "1*2*3-45+67+8+9", "1*2*34+56-7-8*9", "1*2*34-5+6-7-8-9", "1*2+3*4-56+78+9", "1*2+3+4+5*6+7+8-9", "1*2+3+4-5+6*7+8-9", "1*2+3+4-5-6+7*8-9", "1*2+3+45+67-8*9", "1*2+3-45+6+7+8*9", "1*2+34+5-6-7+8+9", "1*2+34+56-7*8+9", "1*2+34-5+6+7-8+9", "1*2+34-56+7*8+9", "1*2+34-56-7+8*9", "1*2-3*4+5+67-8-9", "1*2-3+4-5-6*7+89", "1*2-3-4*5+67+8-9", "1*2-3-4+56-7-8+9", "1*2-34+5*6+7*8-9", "1*23+4*5-6+7-8+9", "1*23-4-56-7+89", "1+2*3*4*5+6+7-89", "1+2*3*4+5*6+7-8-9", "1+2*3*4-5+6*7-8-9", "1+2*3+4*5*6+7-89", "1+2*3+4*5-6+7+8+9", "1+2*3-4-5-6*7+89", "1+2*34-5*6+7+8-9", "1+2+3*4*5+6-7-8-9", "1+2+3*4+5+6*7-8-9", "1+2+3*45-6-78-9", "1+2+3+4+5+6+7+8+9", "1+2+3+4+5-6*7+8*9", "1+2+3+4-5*6+7*8+9", "1+2+3+4-5*6-7+8*9", "1+2+3-4*5+6*7+8+9", "1+2+3-4*5-6+7*8+9", "1+2+3-4*5-6-7+8*9", "1+2+3-45+67+8+9", "1+2-3*4*5+6+7+89", "1+2-3*4+5*6+7+8+9", "1+2-3*4-5+6*7+8+9", "1+2-3*4-5-6+7*8+9", "1+2-3*4-5-6-7+8*9", "1+2-3+4*5+6*7-8-9", "1+2-3+45+6-7-8+9", "1+2-3+45-6+7+8-9", "1+2-3-4-5*6+7+8*9", "1+2-3-45-6+7+89", "1+2-34+5+6+7*8+9", "1+2-34+5+6-7+8*9", "1+2-34-5-6+78+9", "1+23*4+5-6-7*8+9", "1+23*4-5-6*7+8-9", "1+23*4-56+7-8+9", "1+23+4+5+6+7+8-9", "1+23+4-5*6+7*8-9", "1+23+4-5-67+89", "1+23-4*5+6*7+8-9", "1+23-4*5-6+7*8-9", "1+23-4-5+6+7+8+9", "1+23-4-5-6*7+8*9", "1+23-45+67+8-9", "1-2*3*4+5-6+78-9", "1-2*3*4-5-6+7+8*9", "1-2*3+4*5+6+7+8+9", "1-2*3+4*5-6*7+8*9", "1-2*3+4+5+6*7+8-9", "1-2*3+4+5-6+7*8-9", "1-2*3+4+56+7-8-9", "1-2*3+45-67+8*9", "1-2*3-4+5*6+7+8+9", "1-2*3-4-5+6*7+8+9", "1-2*3-4-5-6+7*8+9", "1-2*3-4-5-6-7+8*9", "1-2*34+5*6-7+89", "1-2+3*4*5-6-7+8-9", "1-2+3+4-5*6+78-9", "1-2+3+45+6-7+8-9", "1-2+3-4*5-6+78-9", "1-2+3-45+6-7+89", "1-2-3*4+5+6+7*8-9", "1-2-3*4-5-6+78-9", "1-2-3+4-5+67-8-9", "1-2-3+45-6-7+8+9", "1-2-34+5+6+78-9", "1-2-34+56+7+8+9", "1-2-34-5+6+7+8*9", "1-23*4+5+6*7+89", "1-23+4*5-6*7+89", "1-23+4-5+67-8+9", "1-23+45-67+89", "1-23-4+5+67+8-9", "1-23-4-5-6-7+89", "12*3*4-5*6-78+9", "12*3+4+5+6-7-8+9", "12*3+4+5-6+7+8-9", "12*3-4-5-6+7+8+9", "12*3-4-56+78-9", "12+3*4+5+6-7+8+9", "12+3*45-6-7-89", "12+3+4-56-7+89", "12+3-4*5+67-8-9", "12+3-45+6+78-9", "12+34-5-6-7+8+9", "12-3*4*5+6+78+9", "12-3*4-5+67-8-9", "12-3+4*5+6-7+8+9", "12-3+4+56-7-8-9", "12-3-4+5*6-7+8+9", "12-3-4-56+7+89", "12-3-45-6+78+9"};
	result = solution.addOperators(num, target);
	difference.clear();
	difference.resize(result.size());
	sort(begin(result), end(result));
	sort(begin(answer), end(answer));
	it = set_difference(begin(result), end(result), begin(answer), end(answer), begin(difference));
	difference.resize(distance(begin(difference), it));
	assert(answer == result);

	num = "123";
	target = 6;
	answer = {"1+2+3", "1*2*3"};
	result = solution.addOperators(num, target);
	difference.clear();
	difference.resize(result.size());
	sort(begin(result), end(result));
	sort(begin(answer), end(answer));
	it = set_difference(begin(result), end(result), begin(answer), end(answer), begin(difference));
	difference.resize(distance(begin(difference), it));
	assert(answer == result);

	num = "232";
	target = 8;
	answer = {"2*3+2", "2+3*2"};
	result = solution.addOperators(num, target);
	difference.clear();
	difference.resize(result.size());
	sort(begin(result), end(result));
	sort(begin(answer), end(answer));
	it = set_difference(begin(result), end(result), begin(answer), end(answer), begin(difference));
	difference.resize(distance(begin(difference), it));
	assert(answer == result);

	num = "105";
	target = 5;
	answer = {"1*0+5","10-5"};
	result = solution.addOperators(num, target);
	difference.clear();
	difference.resize(result.size());
	sort(begin(result), end(result));
	sort(begin(answer), end(answer));
	it = set_difference(begin(result), end(result), begin(answer), end(answer), begin(difference));
	difference.resize(distance(begin(difference), it));
	assert(answer == result);

	num = "00";
	target = 0;
	answer = {"0+0", "0-0", "0*0"};
	result = solution.addOperators(num, target);
	difference.clear();
	difference.resize(result.size());
	sort(begin(result), end(result));
	sort(begin(answer), end(answer));
	it = set_difference(begin(result), end(result), begin(answer), end(answer), begin(difference));
	difference.resize(distance(begin(difference), it));
	assert(answer == result);

	num = "3456237490";
	target = 9191;
	answer = {};
	result = solution.addOperators(num, target);
	difference.clear();
	difference.resize(result.size());
	sort(begin(result), end(result));
	sort(begin(answer), end(answer));
	it = set_difference(begin(result), end(result), begin(answer), end(answer), begin(difference));
	difference.resize(distance(begin(difference), it));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}