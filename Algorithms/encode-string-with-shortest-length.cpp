// 471. Encode String with Shortest Length
// https://leetcode.com/problems/encode-string-with-shortest-length/

/*
Given a non-empty string, encode the string such that its encoded length is the shortest.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.

Note:
k will be a positive integer and encoded string will not be empty or have extra space.
You may assume that the input string contains only lowercase English letters. The string's length is at most 160.
If an encoding process does not make the string shorter, then do not encode it. If there are several solutions, return any of them is fine.
Example 1:

Input: "aaa"
Output: "aaa"
Explanation: There is no way to encode it such that it is shorter than the input string, so we do not encode it.
Example 2:

Input: "aaaaa"
Output: "5[a]"
Explanation: "5[a]" is shorter than "aaaaa" by 1 character.
Example 3:

Input: "aaaaaaaaaa"
Output: "10[a]"
Explanation: "a9[a]" or "9[a]a" are also valid solutions, both of them have the same length = 5, which is the same as "10[a]".
Example 4:

Input: "aabcaabcd"
Output: "2[aabc]d"
Explanation: "aabc" occurs twice, so one answer can be "2[aabc]d".
Example 5:

Input: "abbbabbbcabbbabbbc"
Output: "2[2[abbb]c]"
Explanation: "abbbabbbc" occurs twice, but "abbbabbbc" can also be encoded to "2[abbb]c", so one answer can be "2[2[abbb]c]".
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string encode(string s) {
		int sz = s.size(), i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
		if (sz  < 5) {
			return s;
		}
		string t, u;
		vector<vector<string>> A(sz, vector<string>(sz, ""));
		for (i = 1; i <= sz; ++i) {
			for (j = 0; i + j <= sz; ++j) {
				k = i + j - 1;
				A[j][k] = s.substr(j, i);
				if (i >= 5) {
					for (l = 1; l < i; ++l) {
						if (A[j][j + l - 1].size() + A[j + l][k].size() < A[j][k].size()) {
							A[j][k] = A[j][j + l - 1] + A[j + l][k];
						}
					}
					for (l = 1; l <= i / 2; ++l) {
						if (i % l == 0) {
							t.clear();
							n = i / l;
							for (m = 0; m < n; ++m) {
								t.append(s.substr(j, l));
							}
							if (t == s.substr(j, i)) {
								u = to_string(n) + "[" + A[j][j + l - 1] + "]";
								if (u.size() < A[j][k].size()) {
									A[j][k] = u;
								}
							}
						}
					}
				}
			}
		}
		return A[0][sz - 1];
	}
};

int main(void) {
	Solution solution;
	string s, result;

	s = "aaa";
	result = solution.encode(s);
	cout << result << '\n';

	s = "aaaaa";
	result = solution.encode(s);
	cout << result << '\n';
	
	s = "aaaaaaaaaa";
	result = solution.encode(s);
	cout << result << '\n';
	
	s = "aabcaabcd";
	result = solution.encode(s);
	cout << result << '\n';
	
	s = "abbbabbbcabbbabbbc";
	result = solution.encode(s);
	cout << result << '\n';
	
	return 0;
}