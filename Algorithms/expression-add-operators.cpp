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

	cout << "\nPassed All\n";
	return 0;
}