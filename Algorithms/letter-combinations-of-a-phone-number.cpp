// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty()) {
			return {};
		}
		vector<string> table = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, result;
		string s;
		dfs(result, table, digits, s, 0, digits.size());
		return result;
	}
private:
	void dfs(vector<string>& result, const vector<string>& table, const string& digits, string& s, size_t i, const size_t n) {
		if (s.size() == n) {
			result.push_back(s);
			return;
		}
		for (size_t j = i; j < n; j++) {
			const int id = digits[j] - '2';
			const string& t = table[id];
			for (const auto &k : t) {
				s.push_back(k);
				dfs(result, table, digits, s, j + 1, n);
				s.pop_back();
			}
		}
	}
};

int main(void) {
	Solution solution;

	string digits;
	vector<string> answer, result;

	digits = "";
	answer = {};
	sort(begin(answer), end(answer));
	result = solution.letterCombinations(digits);
	sort(begin(result), end(result));
	assert(answer == result);

	digits = "23";
	answer = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
	sort(begin(answer), end(answer));
	result = solution.letterCombinations(digits);
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}