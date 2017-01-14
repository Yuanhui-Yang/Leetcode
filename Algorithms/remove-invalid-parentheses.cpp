// 301. Remove Invalid Parentheses
// https://leetcode.com/problems/remove-invalid-parentheses/
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator> 
using namespace std;
class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		if (s.empty()) {
			return vector<string>({""});
		}
		if (isValid(s)) {
			return vector<string>({s});
		}
		unordered_set<string> result;
		vector<unordered_set<string>> OPT(s.size() + 1);
		OPT[s.size()].insert(s);
		for (size_t len = s.size() - 1; len >= 1; len--) {
			for (const auto &parent : OPT[len + 1]) {
				for (size_t i = 0; i < parent.size(); i++) {
					const string candidate = parent.substr(0, i) + parent.substr(i + 1, parent.size() - i);
					if (isValid(candidate)) {
						result.insert(candidate);
						continue;
					}
					OPT[len].insert(candidate);
				}
			}
			if (!result.empty()) {
				return vector<string>(begin(result), end(result));
			}
		}
		return vector<string>({""});
	}
private:
	bool isValid(const string& s) {
		vector<char> stack;
		for (const auto &c : s) {
			if (c == '(') {
				stack.push_back(c);
				continue;
			}
			if (c == ')') {
				if (stack.empty()) {
					return false;
				}
				stack.pop_back();
				continue;
			}
		}
		return stack.empty();
	}
};

// BEGIN: Time Limit Exceeded
// class Solution {
// public:
// 	vector<string> removeInvalidParentheses(string s) {
// 		if (s.empty()) {
// 			return vector<string>({""});
// 		}
// 		if (isValid(s)) {
// 			return vector<string>({s});
// 		}
// 		vector<string> result;
// 		vector<vector<string>> OPT(s.size() + 1);
// 		OPT[s.size()].push_back(s);
// 		for (size_t len = s.size() - 1; len >= 1; len--) {
// 			for (const auto &parent : OPT[len + 1]) {
// 				for (size_t i = 0; i < parent.size(); i++) {
// 					const string candidate = parent.substr(0, i) + parent.substr(i + 1, parent.size() - i);
// 					if (isValid(candidate)) {
// 						if (find(begin(result), end(result), candidate) == end(result)) {
// 							result.push_back(candidate);
// 						}						
// 						continue;
// 					}
// 					if (find(begin(OPT[len]), end(OPT[len]), candidate) == end(OPT[len])) {
// 						OPT[len].push_back(candidate);
// 						continue;
// 					}
// 				}
// 			}
// 			if (!result.empty()) {
// 				return result;
// 			}
// 		}
// 		return vector<string>({""});
// 	}
// private:
// 	bool isValid(const string& s) {
// 		vector<char> stack;
// 		for (const auto &c : s) {
// 			if (c == '(') {
// 				stack.push_back(c);
// 				continue;
// 			}
// 			if (c == ')') {
// 				if (stack.empty()) {
// 					return false;
// 				}
// 				stack.pop_back();
// 				continue;
// 			}
// 		}
// 		return stack.empty();
// 	}
// };
// END: Time Limit Exceeded
int main(void) {
	Solution solution;
	vector<string> result;

	result = solution.removeInvalidParentheses("");
	sort(begin(result), end(result));
	assert(vector<string>({""}) == result);	

	result = solution.removeInvalidParentheses("()())()");
	sort(begin(result), end(result));
	assert(vector<string>({"(())()", "()()()"}) == result);

	result = solution.removeInvalidParentheses("(a)())()");
	sort(begin(result), end(result));
	assert(vector<string>({"(a())()", "(a)()()"}) == result);
	
	result = solution.removeInvalidParentheses(")(");
	sort(begin(result), end(result));
	assert(vector<string>({""}) == result);

	result = solution.removeInvalidParentheses("(r(()()(");
	sort(begin(result), end(result));
	assert(vector<string>({"(r())", "(r)()", "r(())", "r()()"}) == result);

	result = solution.removeInvalidParentheses("i))((()(n(())i((((");
	sort(begin(result), end(result));
	assert(vector<string>({"i((()n))i", "i(()(n))i", "i(()n())i", "i()(n())i", "i()n(())i"}) == result);	

	cout << "\nPassed All\n";
	return 0;
}