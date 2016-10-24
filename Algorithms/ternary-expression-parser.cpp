// 439. Ternary Expression Parser
// https://leetcode.com/problems/ternary-expression-parser/
#include <iostream>
#include <string>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/64418/5ms-c-fast-solution
class Solution {
public:
	string parseTernary(string expression) {
		const int n = expression.size();
		int i = 0, j = 0, k = 1;
		while (i < n && expression[i] != '?') i++;
		if (i == n) return expression;
		j = ++i;
		while (j < n) {
			if (expression[j] == '?') k++;
			if (expression[j] == ':') k--;
			if (k == 0) break; 
			j++;
		}
		return expression[0] == 'T' ? this->parseTernary(expression.substr(i, j - i)) : this->parseTernary(expression.substr(j + 1));
	}
};
// class Solution {
// public:
// 	string parseTernary(string expression) {
// 		return this->parseTernary(expression, 0, (int)expression.size());
// 	}
// private:
// 	string parseTernary(const string& expression, int i, int j) {
// 		int x = i, y = 0, z = 1;
// 		while (x < j && expression[x] != '?') x++;
// 		if (x == j) return expression.substr(i, j - i);
// 		y = ++x;
// 		while (y < j && z) {
// 			if (expression[y] == '?') z++;
// 			if (expression[y] == ':') z--;
// 			y++;
// 		}
// 		return expression[i] == 'T' ? this->parseTernary(expression, x, y - 1) : this->parseTernary(expression, y, j); 
// 	}
// };
// END: https://discuss.leetcode.com/topic/64418/5ms-c-fast-solution
int main(void) {
	Solution solution;
	cout << solution.parseTernary("T?2:3") << "\tPassed\n";
	cout << solution.parseTernary("F?1:T?4:5") << "\tPassed\n";
	cout << solution.parseTernary("T?T?F:5:3") << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}