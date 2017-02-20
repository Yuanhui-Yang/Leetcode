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
		addOperators("", (long long)target, num, result);
		return result;
	}
private:
	void addOperators(const string current, const long long target, const string num, vector<string>& result) {
		if (num.empty()) {
			
		}
	}
};
int main(void) {
	Solution solution;
	string num;
	int target = 0;
	vector<string> result;
	vector<string> answer;

	num = "123";
	target = 6;
	answer = {"1+2+3", "1*2*3"};
	result = solution.addOperators(num, target);
	assert(unordered_multiset<string>(begin(answer), end(answer)) == unordered_multiset<string>(begin(result), end(result)));

	num = "232";
	target = 8;
	answer = {"2*3+2", "2+3*2"};
	result = solution.addOperators(num, target);
	assert(unordered_multiset<string>(begin(answer), end(answer)) == unordered_multiset<string>(begin(result), end(result)));

	num = "105";
	target = 5;
	answer = {"1*0+5","10-5"};
	result = solution.addOperators(num, target);
	assert(unordered_multiset<string>(begin(answer), end(answer)) == unordered_multiset<string>(begin(result), end(result)));

	num = "00";
	target = 0;
	answer = {"0+0", "0-0", "0*0"};
	result = solution.addOperators(num, target);
	assert(unordered_multiset<string>(begin(answer), end(answer)) == unordered_multiset<string>(begin(result), end(result)));

	num = "3456237490";
	target = 9191;
	answer = {};
	result = solution.addOperators(num, target);
	assert(unordered_multiset<string>(begin(answer), end(answer)) == unordered_multiset<string>(begin(result), end(result)));

	cout << "\nPassed All\n";
	return 0;
}