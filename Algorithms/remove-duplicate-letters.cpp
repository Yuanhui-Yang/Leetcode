// 316. Remove Duplicate Letters
// https://leetcode.com/problems/remove-duplicate-letters/
#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
	string removeDuplicateLetters(string s) {

	}
};
int main(void) {
	Solution solution;
	string s;
	string result;
	string answer;

	result = "bcabc";
	answer = "abc";
	result = solution.removeDuplicateLetters(s);
	assert(answer == result);

	result = "cbacdcbc";
	answer = "acdb";
	result = solution.removeDuplicateLetters(s);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}