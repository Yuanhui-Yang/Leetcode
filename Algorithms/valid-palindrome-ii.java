// 680. Valid Palindrome II
// https://leetcode.com/problems/valid-palindrome-ii/

/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/

class Solution {
	public boolean validPalindrome(String s) {
		if (s == null) {
			return false;
		}
		int len = s.length(), i = 0, j = len - 1;
		while (i < j) {
			if (s.charAt(i) == s.charAt(j)) {
				++i;
				--j;
			}
			else {
				return f(s, i + 1, j) || f(s, i, j - 1);
			}
		}
		return true;
	}
	private boolean f(String s, int i, int j) {
		while (i < j) {
			if (s.charAt(i) == s.charAt(j)) {
				++i;
				--j;
			}
			else {
				return false;
			}
		}
		return true;
	}
}