// 425. Word Squares
// https://leetcode.com/problems/word-squares/
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
	vector<vector<string>> wordSquares(vector<string>& words) {

	}
};
int main(void) {
	Solution solution;
	vector<string> words;
	vector<vector<string>> result;
	words = {"area","lead","wall","lady","ball"};
	result = solution.wordSquares(words);
	assert(unordered_set<vector<string>>() == result);
	cout << "\nPassed All\n";
	return 0;
}