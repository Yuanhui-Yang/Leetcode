// 320. Generalized Abbreviation
// https://leetcode.com/problems/generalized-abbreviation/

/*
Write a function to generate the generalized abbreviations of a word.

Example:
Given word = "word", return the following list (order does not matter):
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
*/

class Solution {
public:
	vector<string> generateAbbreviations(string word) {
		vector<string> result;
		string s;
		f(result, s, word, 0, 0);
		return result;
	}
private:
	void f(vector<string> & result, string & s, string & word, int i, int k) {
		int M = s.size(), N = word.size();
		if (i == N) {
			if (k) {
				s.append(to_string(k));	
			}
			result.push_back(s);
		}
		else {
			f(result, s, word, i + 1, k + 1);
			if (k) {
				s.append(to_string(k));
			}
			s.push_back(word[i]);
			f(result, s, word, i + 1, 0);
		}
		s = s.substr(0, M);
	}
};