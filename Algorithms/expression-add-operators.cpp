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
					addOperators(solution + "0", "", 0, target, "", result);
					return;
				}
				if (num.size() >= 2) {
					addOperators(solution + "0+", "", 0, target, num.substr(1), result);
					addOperators(solution + "0-", "", 0, -target, num.substr(1), result);
					addOperators(solution, "0", 0, target, num.substr(1), result);
					return;
				}
				return;
			}
			if (!multiple_str.empty()) {
				if (num.size() == 1) {
					addOperators(solution + multiple_str + "*0", "", 0, target, "", result);
					return;
				}
				if (num.size() >= 2) {
					addOperators(solution + multiple_str + "*0+", "", 0, target, num.substr(1), result);
					addOperators(solution + multiple_str + "*0-", "", 0, -target, num.substr(1), result);
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
					addOperators(solution + num.substr(0, len) + "+", "", 0, target - stoll(num.substr(0, len)), num.substr(len), result);
					addOperators(solution + num.substr(0, len) + "-", "", 0, stoll(num.substr(0, len)) - target, num.substr(len), result);
					addOperators(solution, num.substr(0, len), stoll(num.substr(0, len)), target, num.substr(len), result);
				}
				addOperators(solution + num, "", 0, target - stoll(num), "", result);
				return;
			}
			if (!multiple_str.empty()) {
				for (size_t len = 1; len < num.size(); len++) {
					addOperators(solution + multiple_str + "*" + num.substr(0, len) + "+", "", 0, target - multiple_val * stoll(num.substr(0, len)), num.substr(len), result);
					addOperators(solution + multiple_str + "*" + num.substr(0, len) + "-", "", 0, multiple_val * stoll(num.substr(0, len)) - target, num.substr(len), result);
					addOperators(solution, multiple_str + "*" + num.substr(0, len), multiple_val * stoll(num.substr(0, len)), target, num.substr(len), result);
				}
				addOperators(solution + multiple_str + "*" + num, "", 0, target - multiple_val * stoll(num), "", result);
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
	cout << '\n';
	for (const auto &i : result) {
		cout << i << '\t';
	}
	cout << '\n';
	assert(difference.empty());

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
	assert(difference.empty());

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
	assert(difference.empty());

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
	assert(difference.empty());

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
	assert(difference.empty());

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
	assert(difference.empty());

	cout << "\nPassed All\n";
	return 0;
}