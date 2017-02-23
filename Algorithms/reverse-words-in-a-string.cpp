// 151. Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	void reverseWords(string &s) {
		
	}
};
int main(void) {
	Solution solution;
	string s;
	string answer;

	s = "the sky is blue";
	answer = "blue is sky the";
	solution.reverseWords(s);
	assert(answer == s);

	cout << "\nPassed All\n";
	return 0;
}