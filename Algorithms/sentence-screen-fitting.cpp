// 418. Sentence Screen Fitting
// https://leetcode.com/problems/sentence-screen-fitting/
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// BEGIN: Time Limit Exceeded
class Solution {
public:
	int wordsTyping(vector<string>& sentence, int rows, int cols) {
		int result = 0;
		const int m = sentence.size();
		if (m == 1) {
			const int n = sentence[0].size();
			if (n > cols) return 0;
			if (n == cols) return rows;
			if (cols & 0b01) return rows * ((cols + 1) >> 1); 
			else return rows * (cols >> 1);
		}
		int remain = cols;
		while (rows > 0) {
			int i = 0;
			for (i = 0; rows > 0 && i < m; i++) {
				const int n = sentence[i].size();
				if (n > cols) return 0;
				if (remain == cols) {
					remain -= n;
					continue;
				}
				if (remain < n + 1) {
					remain = cols;
					rows--;
					i--;
					continue;
				}
				if (remain == n + 1) {
					remain = cols;
					rows--;
					continue;
				}
				if (remain > n + 1) {
					remain -= n + 1;
					continue;
				}
			}
			if (i == m) result++;
		}
		return result;
	}
};
// END: Time Limit Exceeded
int main(void) {
	Solution solution;
	vector<string> sentence = {"hello", "world"};
	assert(1 == solution.wordsTyping(sentence, 2, 8));
	sentence = {"a", "bcd", "e"};
	assert(2 == solution.wordsTyping(sentence, 3, 6));
	sentence = {"I", "had", "apple", "pie"};
	assert(1 == solution.wordsTyping(sentence, 4, 5));
	sentence = {"a"};
	assert(200000000 == solution.wordsTyping(sentence, 20000, 20000));
	cout << "\nPassed All\n";
	return 0;
}