// 150. Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		if (tokens.empty()) {
			return 0;
		}
		stack<int> stk;
		unordered_map<string, int> h;
		h["+"] = 1;
		h["-"] = 1;
		h["*"] = 2;
		h["/"] = 2;
		for (const auto & i : tokens) {
			if (h.count(i)) {
				int y = stk.top();
				stk.pop();
				int x = stk.top();
				stk.pop();
				int z = i == "*" ? x * y : i == "/" ? x / y : i == "+" ? x + y : x - y;
				stk.push(z);
			}
			else {
				stk.push(stoi(i));
			}
		}
		return stk.top();
	}
};