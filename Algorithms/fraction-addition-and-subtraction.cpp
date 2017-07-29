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

class Solution {
public:
	string fractionAddition(string expression) {
		if (expression.empty()) {
			return "0";
		}
		int sz = expression.size(), i = 0, base = 10;
		stack<array<int, 2>> a;
		stack<char> b;
		array<int, 256> A;
		A.fill(0);
		A['+'] = 1;
		A['-'] = 1;
		A['/'] = 2;
		if (expression[0] == '-') {
			a.push({0, 1});
			b.push('-');
			++i;
		}
		for (; i < sz; ++i) {
			if (expression[i] == ' ') {
				continue;
			}
			if (isdigit(expression[i])) {
				int val = expression[i] - '0';
				while (i + 1 < sz and isdigit(expression[i + 1])) {
					val = base * val + expression[i + 1] - '0';
					++i;
				}
				a.push({val, 1});
				continue;
			}
			if (A[expression[i]] > 0) {
				while (!b.empty() and A[b.top()] >= A[expression[i]]) {
					array<int, 2> y = a.top();
					a.pop();
					array<int, 2> x = a.top();
					a.pop();
					char op = b.top();
					b.pop();
					if (op == '+') {
						a.push(f1(x, y));
					}
					else if (op == '-') {
						a.push(f2(x, y));
					}
					else if (op == '*') {
						a.push(f3(x, y));
					}
					else if (op == '/') {
						a.push(f4(x, y));
					}
				}
				b.push(expression[i]);
				continue;
			}
		}
		while (!b.empty()) {
			array<int, 2> y = a.top();
			a.pop();
			array<int, 2> x = a.top();
			a.pop();
			char op = b.top();
			b.pop();
			if (op == '+') {
				a.push(f1(x, y));
			}
			else if (op == '-') {
				a.push(f2(x, y));
			}
			else if (op == '*') {
				a.push(f3(x, y));
			}
			else if (op == '/') {
				a.push(f4(x, y));
			}
		}
		return to_string(a.top()[0]) + "/" + to_string(a.top()[1]);
	}
private:
	array<int, 2> f1(const array<int, 2> & x, const array<int, 2> & y) {
		array<int, 2> result;
		result[0] = x[0] * y[1] + x[1] * y[0];
		result[1] = x[1] * y[1];
		int d = gcd(result[0], result[1]);
		result[0] /= d;
		result[1] /= d;
		if (result[1] < 0) {
			result[0] = -result[0];
			result[1] = -result[1];
		}
		return result;
	}
	array<int, 2> f2(const array<int, 2> & x, const array<int, 2> & y) {
		array<int, 2> result;
		result[0] = x[0] * y[1] - x[1] * y[0];
		result[1] = x[1] * y[1];
		int d = gcd(result[0], result[1]);
		result[0] /= d;
		result[1] /= d;
		if (result[1] < 0) {
			result[0] = -result[0];
			result[1] = -result[1];
		}
		return result;
	}
	array<int, 2> f3(const array<int, 2> & x, const array<int, 2> & y) {
		array<int, 2> result;
		result[0] = x[0] * y[0];
		result[1] = x[1] * y[1];
		int d = gcd(result[0], result[1]);
		result[0] /= d;
		result[1] /= d;
		if (result[1] < 0) {
			result[0] = -result[0];
			result[1] = -result[1];
		}
		return result;
	}
	array<int, 2> f4(const array<int, 2> & x, const array<int, 2> & y) {
		array<int, 2> result;
		result[0] = x[0] * y[1];
		result[1] = x[1] * y[0];
		int d = gcd(result[0], result[1]);
		result[0] /= d;
		result[1] /= d;
		if (result[1] < 0) {
			result[0] = -result[0];
			result[1] = -result[1];
		}
		return result;
	}
private:
	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
};