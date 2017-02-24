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
		if (s.empty()) {
			return;
		}
		while (!s.empty() && s.back() == ' ') {
			s.pop_back();
		}
		if (s.empty()) {
			return;
		}
		reverse(begin(s), end(s));
		while (!s.empty() && s.back() == ' ') {
			s.pop_back();
		}
		if (s.empty()) {
			return;
		}
		for (size_t i = 0, j = 0; i < s.size(); i++) {
			if (s.at(i) != ' ') {
				j = i;
				while (i + 1 < s.size() && s.at(i + 1) != ' ') {
					i++;
				}
				reverse(next(begin(s), j), next(begin(s), i + 1));
				continue;
			}
			if (s.at(i) == ' ') {
				j = i;
				while (i + 1 < s.size() && s.at(i + 1) == ' ') {
					i++;
				}
				const size_t d = i - j;
				s.erase(next(begin(s), j), next(begin(s), i));
				i -= d;
				continue;
			}
		}
	}
};
int main(void) {
	Solution solution;
	string s;
	string answer;

	s = "   one.   +two three?   ~four   !five- ";
	answer = "!five- ~four three? +two one.";
	solution.reverseWords(s);
	assert(answer == s);

	s = "the sky is blue";
	answer = "blue is sky the";
	solution.reverseWords(s);
	assert(answer == s);

	cout << "\nPassed All\n";
	return 0;
}