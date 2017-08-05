// 640. Solve the Equation
// https://leetcode.com/problems/solve-the-equation/

/*
Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.

If there is no solution for the equation, return "No solution".

If there are infinite solutions for the equation, return "Infinite solutions".

If there is exactly one solution for the equation, we ensure that the value of x is an integer.

Example 1:
Input: "x+5-3+x=6+x-2"
Output: "x=2"
Example 2:
Input: "x=x"
Output: "Infinite solutions"
Example 3:
Input: "2x=x"
Output: "x=0"
Example 4:
Input: "2x+3x-6x=x+2"
Output: "x=-1"
Example 5:
Input: "x=x+2"
Output: "No solution"
*/

class Solution {
public:
	string solveEquation(string equation) {
		int sz = equation.size();
		if (sz < 3) {
			return "No solution";
		}
		int i = 0;
		while (i < sz and equation[i] != '=') {
			++i;
		}
		string left = equation.substr(0, i), right = equation.substr(i + 1);
		if (left[0] != '-') {
			left.insert(begin(left), '+');
		}
		if (right[0] != '-') {
			right.insert(begin(right), '+');
		}
		array<int, 2> A = f(left), B = f(right);
		A[0] -= B[0];
		B[1] -= A[1];
		if (A[0] == 0 and B[1] == 0) {
			return "Infinite solutions";
		}
		if (A[0] == 0) {
			return "No solution";
		}
		return string("x=") + string(to_string(B[1] / A[0]));
	}
private:
	array<int, 2> f(const string & s) {
		int sz = s.size();
		array<int, 2> result({0, 0});
		for (int i = 0; i < sz; ++i) {
			int sign = s[i] == '-' ? -1 : 1;
			++i;
			int val = 0;
			while (i < sz and isdigit(s[i])) {
				val = 10 * val + s[i] - '0';
				++i;
			}
			if (i < sz and s[i] == 'x') {
				if (s[i - 1] == '-' or s[i - 1] == '+') {
					val = 1;
				}
				result[0] += sign * val;
			}
			else {
				result[1] += sign * val;
				--i;
			}
		}
		return result;
	}
};