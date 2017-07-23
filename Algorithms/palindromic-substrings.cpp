// 647. Palindromic Substrings
// https://leetcode.com/problems/palindromic-substrings/

/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.
*/

class Solution {
public:
	int countSubstrings(string s) {
		string t;
		t.push_back('#');
		for (const auto & i : s) {
			t.push_back(i);
			t.push_back('#');
		}
		int sz = t.size(), x = 0, y = 0;
		vector<int> A(sz, 0);
		for (int i = 0; i < sz; ++i) {
			int j = 2 * x - i;
			if (j > x - y and j - A[j] > x - y) {
				A[i] = A[j];
			}
			else {
				int k = 0;
				while (i - k >= 0 and i + k < sz and t[i - k] == t[i + k]) {
					++k;
				}
				A[i] = --k;
			}
			if (x + y < i + A[i]) {
				x = i;
				y = A[i];
			}
		}
		int result = 0;
		for (const auto & i : A) {
			result += (i + 1) / 2;
		}
		return result;
	}
};