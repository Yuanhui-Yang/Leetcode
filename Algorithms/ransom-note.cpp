// 383. Ransom Note
// https://leetcode.com/problems/ransom-note/

/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int h[26], m = ransomNote.size(), n = magazine.size();
		memset(h, 0, sizeof(h));
		for (int i = 0; i < n; ++i) {
			int d = magazine[i] - 'a';
			++h[d];
		}
		for (int i = 0; i < m; ++i) {
			int d = ransomNote[i] - 'a';
			if (h[d]-- <= 0) {
				return false;
			}
		}
		return true;
	}
};

int main(void) {
	Solution solution;
	string ransomNote, magazine;
	bool answer, result;

	ransomNote = "a";
	magazine = "b";
	answer = false;
	result = solution.canConstruct(ransomNote, magazine);
	assert(answer == result);

	ransomNote = "aa";
	magazine = "ab";
	answer = false;
	result = solution.canConstruct(ransomNote, magazine);
	assert(answer == result);

	ransomNote = "aa";
	magazine = "aab";
	answer = true;
	result = solution.canConstruct(ransomNote, magazine);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}