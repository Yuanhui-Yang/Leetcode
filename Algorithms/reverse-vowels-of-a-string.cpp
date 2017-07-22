// 345. Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string/

/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
*/

class Solution {
public:
	string reverseVowels(string s) {
		array<bool, 256> A;
		A.fill(false);
		A['a'] = true;
		A['e'] = true;
		A['i'] = true;
		A['o'] = true;
		A['u'] = true;
		A['A'] = true;
		A['E'] = true;
		A['I'] = true;
		A['O'] = true;
		A['U'] = true;
		int sz = s.size(), i = 0, j = sz - 1;
		while (i < j) {
			if (!A[s[i]]) {
				++i;
				continue;
			}
			if (!A[s[j]]) {
				--j;
				continue;
			}
			swap(s[i++], s[j--]);
		}
		return s;
	}
};