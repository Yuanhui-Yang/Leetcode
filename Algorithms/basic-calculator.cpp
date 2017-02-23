// 224. Basic Calculator
// https://leetcode.com/problems/basic-calculator/
#include <iostream>
#include <cassert>
#include <cctype>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	int calculate(string s) {
		if (s.empty()) {
			return 0;
		}
		list<long long> result(1, 0);
		list<size_t> signs;
		for (size_t i = 0, sign = string::npos; i < s.size(); i++) {
			const char ch = s.at(i);
			if (ch == ' ') {
				continue;
			}
			if (ch == '+') {
				sign = i;
				continue;
			}
			if (ch == '-') {
				sign = i;
				continue;
			}
			if (ch == '(') {
				result.push_back(0);
				signs.push_back(sign);
				continue;
			}
			if (ch == ')') {
				const long long result_back = result.back();
				result.pop_back();
				const size_t signs_back = signs.back();
				signs.pop_back();
				if (signs_back == string::npos || s.at(signs_back) == '+') {
					result.back() += result_back;
					continue;
				}
				if (s.at(signs_back) == '-') {
					result.back() -= result_back;
					continue;
				}
				continue;
			}
			if (isdigit(ch)) {
				const size_t j = i;
				while (i + 1 < s.size() && isdigit(s.at(i + 1))) {
					i++;
				}
				const string s_substr = s.substr(j, i + 1 - j);
				const long long stoll_s_substr = stoll(s_substr);
				if (signs.empty()) {
					if (sign == string::npos || s.at(sign) == '+') {
						result.back() += stoll_s_substr;
						continue;
					}
					if (s.at(sign) == '-') {
						result.back() -= stoll_s_substr;
						continue;
					}
					continue;
				}
				if (!signs.empty()) {
					const size_t signs_back = signs.back();
					if (signs_back == sign) {
						result.back() += stoll_s_substr;
						continue;
					}
					if (signs_back != sign) {
						if (s.at(sign) == '+') {
							result.back() += stoll_s_substr;
							continue;
						}
						if (s.at(sign) == '-') {
							result.back() -= stoll_s_substr;
							continue;
						}
						continue;
					}
					continue;					
				}
				continue;
			}
		}
		return int(result.front());
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