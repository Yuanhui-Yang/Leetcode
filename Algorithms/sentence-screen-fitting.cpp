// 418. Sentence Screen Fitting
// https://leetcode.com/problems/sentence-screen-fitting/

/*
Given a rows x cols screen and a sentence represented by a list of non-empty words, find how many times the given sentence can be fitted on the screen.

Note:

A word cannot be split into two lines.
The order of words in the sentence must remain unchanged.
Two consecutive words in a line must be separated by a single space.
Total words in the sentence won't exceed 100.
Length of each word is greater than 0 and won't exceed 10.
1 ≤ rows, cols ≤ 20,000.
Example 1:

Input:
rows = 2, cols = 8, sentence = ["hello", "world"]

Output: 
1

Explanation:
hello---
world---

The character '-' signifies an empty space on the screen.
Example 2:

Input:
rows = 3, cols = 6, sentence = ["a", "bcd", "e"]

Output: 
2

Explanation:
a-bcd- 
e-a---
bcd-e-

The character '-' signifies an empty space on the screen.
Example 3:

Input:
rows = 4, cols = 5, sentence = ["I", "had", "apple", "pie"]

Output: 
1

Explanation:
I-had
apple
pie-I
had--

The character '-' signifies an empty space on the screen.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int wordsTyping(vector<string>& sentence, int rows, int cols) {
		int sz = sentence.size(), i = 0, result = 0;
		if (sz == 0 or rows <= 0 or cols <= 0) {
			return 0;
		}
		vector<int> A(sz);
		for (i = 0; i < sz; ++i) {
			if (cols < sentence[i].size()) {
				return 0;
			}
			A[i] = f1(sentence, cols, i);
		}
		for (i = 0; i < rows; ++i) {
			result += A[result % sz];
		}
		return result / sz;
	}
private:
	int f1(const vector<string> & sentence, int cols, int index) {
		int sz = sentence.size(), result = 1;
		cols -= sentence[index % sz].size();
		++index;
		while (cols >= sentence[index % sz].size() + 1) {
			cols -= sentence[index % sz].size() + 1;
			++index;
			++result;
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<string> sentence;
	int rows, cols, result;
	
	sentence = {"hello", "world"};
	rows = 2;
	cols = 8;
	result = solution.wordsTyping(sentence, rows, cols);
	cout << result << '\n';

	sentence = {"a", "bcd", "e"};
	rows = 3;
	cols = 6;
	result = solution.wordsTyping(sentence, rows, cols);
	cout << result << '\n';

	sentence = {"I", "had", "apple", "pie"};
	rows = 4;
	cols = 6;
	result = solution.wordsTyping(sentence, rows, cols);
	cout << result << '\n';

	return 0;
}