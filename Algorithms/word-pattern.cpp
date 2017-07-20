// 290. Word Pattern
// https://leetcode.com/problems/word-pattern/

/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		array<int, 256> A;
		A.fill(-1);
		unordered_map<string, int> B;
		int X = pattern.size(), Y = str.size(), i = 0, j = 0;
		for (; i < X and j < Y; ++i, ++j) {
			int k = j;
			while (j < Y and str[j] != ' ') {
				++j;
			}
			char key1 = pattern[i];
			string key2 = str.substr(k, j - k);
			if (A[key1] < 0 and !B.count(key2)) {
				A[key1] = i;
				B[key2] = i;
			}
			else if (A[key1] >= 0 and B.count(key2) and A[key1] == B[key2]) {
				A[key1] = i;
				B[key2] = i;
			}
			else {
				return false;
			}
		}
		return i == X and --j == Y;
	}
};