// 409. Longest Palindrome
// https://leetcode.com/problems/longest-palindrome/

/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

class Solution {
public:
	int longestPalindrome(string s) {
		array<int, 256> A;
		A.fill(0);
		for (const auto & i : s) {
			++A[i];
		}
		array<int, 2> B;
		B.fill(0);
		for (int i = 0; i < 256; ++i) {
			if (A[i] % 2) {
				B[0] = 1;
				B[1] += A[i] / 2 * 2;
			}
			else {
				B[1] += A[i];
			}
		}
		return B[0] + B[1];
	}
};