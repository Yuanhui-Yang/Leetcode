// 214. Shortest Palindrome
// https://leetcode.com/problems/shortest-palindrome/

/*
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
*/

class Solution {
public:
	string shortestPalindrome(string s) {
		int m = s.size();
		string t = s;
		reverse(begin(t), end(t));
		s.push_back('#');
		s.append(t);
		int n = s.size(), i = 0, j = -1;
		vector<int> A(n + 1, 0);
		A.front() = -1;
		while (i < n) {
			if (j == -1 or s[i] == s[j]) {
				A[++i] = ++j;
			}
			else {
				j = A[j];
			}
		}
		return t.substr(0, m - A.back()) + s.substr(0, m);
	}
};

class Solution {
public:
	string shortestPalindrome(string s) {
		string t;
		for (const auto & i : s) {
			t.push_back('#');
			t.push_back(i);
		}
		t.push_back('#');
		int p = s.size(), q = t.size(), x = 0, y = 0;
		vector<int> A(q, 0);
		for (int i = 0; i < q and x - y >= 0 and x + y < q; ++i) {
			int j = 2 * x - i;
			if (j >= 0 and j - A[j] > 2 * x - y) {
				A[i] = A[j];
			}
			else {
				int z = 0;
				while (i - z >= 0 and i + z < q and t[i - z] == t[i + z]) {
					++z;
				}
				A[i] = z - 1;
			}
			if (y < A[i]) {
				x = i;
				y = A[i];
			}
		}
		int i = q - 1;
		while (i > 0 and i != A[i]) {
			--i;
		}
		t = s.substr(i);
		reverse(begin(t), end(t));
		return t + s;
	}
};