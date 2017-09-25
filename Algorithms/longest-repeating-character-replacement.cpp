// 424. Longest Repeating Character Replacement
// https://leetcode.com/problems/longest-repeating-character-replacement/

/*
Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.

Note:
Both the string's length and k will not exceed 104.

Example 1:

Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
*/

#include <iostream>
#include <string>
#include <array>

using namespace std;

class Solution {
public:
	int characterReplacement(string s, int k) {
		int sz = s.size(), i = 0, j = 0, l = 0, id = 0, maxCnt = 0, result = 0;
		array<int, 26> A;
		A.fill(0);
		while (j < sz) {
			if (i >= j or j - i - maxCnt <= k) {
				id = s[j] - 'A';
				++A[id];
				++j;
			}
			else {
				id = s[i] - 'A';
				--A[id];
				++i;
			}
			maxCnt = 0;
			for (l = 0; l < 26; ++l) {
				if (maxCnt < A[l]) {
					maxCnt = A[l];
				}
			}
			if (j - i - maxCnt <= k and j - i > result) {
				result = j - i;
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	string s;
	int k, result;
	
	s = "ABAB";
	k = 2;
	result = solution.characterReplacement(s, k);
	cout << result << '\n';

	s = "AABABBA";
	k = 1;
	result = solution.characterReplacement(s, k);
	cout << result << '\n';
	
	return 0;
}