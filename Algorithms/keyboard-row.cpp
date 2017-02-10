// 500. Keyboard Row
// https://leetcode.com/problems/keyboard-row/
#include <iostream>
#include <cassert>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_set>
using namespace std;
class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> result;
		vector<unordered_set<char>> OPT(3);
		OPT[0] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'};
		OPT[1] = {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};
		OPT[2] = {'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
		for (const auto &word : words) {
			if (!word.empty()) {
				int i = 0;
				while (i < 3 && !OPT[i].count(toupper(word.front()))) {
					i++;
				}
				if (i < 3) {
					bool found = true;
					for (const auto &ch : word) {
						if (!OPT[i].count(toupper(ch))) {
							found = false;
							break;
						}
					}
					if (found) {
						result.push_back(word);
					}
				}
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	vector<string> words;
	vector<string> result;

	words = {"Hello", "Alaska", "Dad", "Peace"};
	result = solution.findWords(words);
	assert(unordered_multiset<string>({"Alaska", "Dad"}) == unordered_multiset<string>(begin(result), end(result)));

	cout << "\nPassed All\n";
	return 0;
}