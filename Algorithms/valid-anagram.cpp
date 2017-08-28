// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/

/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) {
			return false;
		}
		sort(begin(s), end(s));
		sort(begin(t), end(t));
		return s == t;
	}
};

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) {
			return false;
		}
		array<int, 26> A, B;
		A.fill(0);
		B.fill(0);
		for (const auto & i : s) {
			++A[i - 'a'];
		}
		for (const auto & i : t) {
			++B[i - 'a'];
		}
		return A == B;
	}
};