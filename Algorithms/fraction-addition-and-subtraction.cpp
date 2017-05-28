// 592. Fraction Addition and Subtraction
// https://leetcode.com/problems/fraction-addition-and-subtraction/

/*
Given a string representing an expression of fraction addition and subtraction, you need to return the calculation result in string format. The final result should be irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of fraction that has denominator 1. So in this case, 2 should be converted to 2/1.

Example 1:
Input:"-1/2+1/2"
Output: "0/1"
Example 2:
Input:"-1/2+1/2+1/3"
Output: "1/3"
Example 3:
Input:"1/3-1/2"
Output: "-1/6"
Example 4:
Input:"5/3+1/3"
Output: "2/1"
Note:
The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
Each fraction (input and output) has format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1,10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
The number of given fractions will be in the range [1,10].
The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string fractionAddition(string expression) {
		if (expression.empty()) {
			return "0";
		}
		list<pair<int, int>> l1;
		list<char> l2;
		unordered_map<char, int> h;
		h['+'] = 2;
		h['-'] = 2;
		h['*'] = 3;
		h['/'] = 3;
		int i = 0, n = expression.size();
		if (expression.front() == '-') {
			l1.push_back(make_pair(0, 1));
			l2.push_back('-');
			i++;
		}
		for ( ; i < n; i++) {
			int j = i;
			char ch = expression[i];
			if (ch == ' ') {
				continue;
			}
			if (isdigit(ch)) {
				while (i < n and isdigit(expression[i])) {
					i++;
				}
				l1.push_back(make_pair(stoi(expression.substr(j, i-- - j)), 1));
				continue;
			}
			if (h.count(ch)) {
				while (!l2.empty() and h[l2.back()] >= h[ch]) {
					char op = l2.back();
					l2.pop_back();
					pair<int, int> b = l1.back();
					l1.pop_back();
					pair<int, int> a = l1.back();
					l1.pop_back();
					pair<int, int> c = op == '+' ? make_pair(a.first * b.second + a.second * b.first, a.second * b.second) : op == '-' ? make_pair(a.first * b.second - a.second * b.first, a.second * b.second) : op == '*' ? make_pair(a.first * b.first, a.second * b.second) : make_pair(a.first * b.second, a.second * b.first);
					int d = gcd(c.first, c.second);
					c.first /= d;
					c.second /= d;
					l1.push_back(c);
				}
				l2.push_back(ch);
				continue;
			}
		}
		while (!l2.empty()) {
			char op = l2.back();
			l2.pop_back();
			pair<int, int> b = l1.back();
			l1.pop_back();
			pair<int, int> a = l1.back();
			l1.pop_back();
			pair<int, int> c = op == '+' ? make_pair(a.first * b.second + a.second * b.first, a.second * b.second) : op == '-' ? make_pair(a.first * b.second - a.second * b.first, a.second * b.second) : op == '*' ? make_pair(a.first * b.first, a.second * b.second) : make_pair(a.first * b.second, a.second * b.first);
			int d = gcd(c.first, c.second);
			c.first /= d;
			c.second /= d;
			l1.push_back(c);
		}
		pair<int, int>& result = l1.front();
		if (result.second < 0) {
			result.first = -result.first;
			result.second = -result.second;
		}
		return to_string(result.first) + "/" + to_string(result.second);
	}
private:
	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
};

int main(void) {
	Solution solution;
	string expression, result, answer;

	expression = "-1/2+1/2";
	answer = "0/1";
	result = solution.fractionAddition(expression);
	assert(answer == result);

	expression = "-1/2+1/2+1/3";
	answer = "1/3";
	result = solution.fractionAddition(expression);
	assert(answer == result);

	expression = "1/3-1/2";
	answer = "-1/6";
	result = solution.fractionAddition(expression);
	assert(answer == result);

	expression = "5/3+1/3";
	answer = "2/1";
	result = solution.fractionAddition(expression);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
