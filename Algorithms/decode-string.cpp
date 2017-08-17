// 394. Decode String
// https://leetcode.com/problems/decode-string/

/*
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

class Solution {
public:
	string decodeString(string s) {
		int sz = s.size();
		if (sz <= 1) {
			return s;
		}
		string result;
		int i = 0;
		while (i < sz and !isdigit(s[i])) {
			result.push_back(s[i]);
			++i;
		}
		if (i >= sz) {
			return result;
		}
		int val = 0;
		while (i < sz and s[i] != '[') {
			val = 10 * val + s[i] - '0';
			++i;
		}
		int cnt = 1;
		++i;
		int j = i;
		while (i < sz) {
			if (s[i] == '[') {
				++cnt;
			}
			else if (s[i] == ']') {
				--cnt;
			}
			if (cnt <= 0) {
				break;
			}
			++i;
		}
		for (int k = 0; k < val; ++k) {
			result.append(decodeString(s.substr(j, i - j)));
		}
		result.append(decodeString(s.substr(i + 1)));
		return result;
	}
};