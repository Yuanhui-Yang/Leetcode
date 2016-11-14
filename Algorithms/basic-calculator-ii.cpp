// 227. Basic Calculator II
// https://leetcode.com/problems/basic-calculator-ii/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/16935/share-my-java-solution
class Solution {
public:
	int calculate(string s) {
		if (s.empty()) return 0;
		int result = 0;
		const int n = s.size();
		char sign = '+';
		for (int i = 0, term = 0, previous = 0; i < n; i++) {
			if (s[i] >= '0' && s[i] <= '9')
				term = 10 * term + s[i] - '0';
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i + 1 == n) {
				if (sign == '+') {
					result += previous;
					previous = term;
				}
				if (sign == '-') {
					result += previous;
					previous = -term;
				}
				if (sign == '*') previous *= term;
				if (sign == '/') previous /= term;
				term = 0;
				sign = s[i];
				if (i + 1 == n) result += previous;
			}
		}
		return result;
	}
};

// class Solution {
// public:
// 	int calculate(string s) {
// 		if (s.empty()) return 0;
// 		vector<int> stack;
// 		const int n = s.size();
// 		char sign = '+';
// 		for (int i = 0, term = 0; i < n; i++) {
// 			if (s[i] >= '0' && s[i] <= '9')
// 				term = 10 * term + (s[i] - '0');
// 			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i + 1 == n) {
// 				if (sign == '+') stack.push_back(term);
// 				if (sign == '-') stack.push_back(-term);
// 				if (sign == '*') stack.back() *= term;
// 				if (sign == '/') stack.back() /= term;
// 				term = 0;
// 				sign = s[i];
// 			}
// 		}
// 		return accumulate(begin(stack), end(stack), 0);
// 	}
// };
// END: https://discuss.leetcode.com/topic/16935/share-my-java-solution

// BEGIN: https://discuss.leetcode.com/topic/16807/17-lines-c-easy-20-ms
// class Solution {
// public:
// 	int calculate(string s) {
// 		if (s.empty()) return 0;
// 		int result = 0, term = 0, n;
// 		istringstream in('+' + s + '+');
// 		char opt;
// 		while (in >> opt) {
// 			if (opt == '+' || opt == '-') {
// 				result += term;
// 				in >> term;
// 				term *= 44 - opt;
// 			}
// 			else {
// 				in >> n;
// 				if (opt == '*') term *= n;
// 				else term /= n;
// 			}
// 		}
// 		return result;
// 	}
// };
// END: https://discuss.leetcode.com/topic/16807/17-lines-c-easy-20-ms

// class Solution {
// public:
// 	int calculate(string s) {
// 		if (s.empty()) return 0;
// 		const int n = s.size();
// 		vector<string> stack; 
// 		for (int i = 0, j = 0; i < n; ) {
// 			while (i < n && s[i] == ' ') i++;
// 			if (i == n) break;
// 			if (s[i] == '*' || s[i] == '/') {
// 				int opt = i;
// 				if (stack.empty()) break;
// 				i++;
// 				while (i < n && s[i] == ' ') i++;
// 				if (i == n) break;
// 				if (!(s[i] >= '0' && s[i] <= '9')) break;
// 				j = i++;
// 				while (i < n && s[i] >= '0' && s[i] <= '9') i++;
// 				if (s[opt] == '*') stack.back() = to_string(stoi(stack.back()) * stoi(s.substr(j, i - j)));
// 				if (s[opt] == '/') stack.back() = to_string(stoi(stack.back()) / stoi(s.substr(j, i - j)));
// 				continue;
// 			}
// 			if (s[i] == '+' || s[i] == '-') {
// 				stack.push_back(string(1, s[i++]));
// 				continue;
// 			}
// 			j = i++;
// 			while (i < n && s[i] >= '0' && s[i] <= '9') i++;
// 			stack.push_back(s.substr(j, i - j));
// 		}
// 		if (stack.empty()) return 0;
// 		int result = 0;
// 		const int stack_size = stack.size();
// 		for (int i = 0; i < stack_size; ) {
// 			if (i == 0) {
// 				if (stack[i] == "+" || stack[i] == "-") return result;
// 				result = stoi(stack[i++]);
// 				continue;
// 			}
// 			if (stack[i] == "+") {
// 				if (i + 1 == stack_size) return result;
// 				result += stoi(stack[++i]);
// 				i++;
// 				continue;
// 			}
// 			if (stack[i] == "-") {
// 				if (i + 1 == stack_size) return result;
// 				result -= stoi(stack[++i]);
// 				i++;
// 				continue;				
// 			}
// 			return result;
// 		}
// 		return result;
// 	}
// };
int main(void) {
	Solution solution;
	cout << solution.calculate("3+2*2") << "\tPassed\n";
	cout << solution.calculate(" 3/2 ") << "\tPassed\n";
	cout << solution.calculate(" 3+5 / 2 ") << "\tPassed\n";
	cout << solution.calculate("42") << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}