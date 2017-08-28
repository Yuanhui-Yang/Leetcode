// 438. Find All Anagrams in a String
// https://leetcode.com/problems/find-all-anagrams-in-a-string/

/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int sz1 = s.size(), sz2 = p.size();
		if (sz1 < sz2) {
			return {};
		}
		vector<int> result;
		array<int, 26> A;
		A.fill(0);
		for (const auto & i : p) {
			++A[i - 'a'];
		}
		array<int, 26> B;
		B.fill(0);
		int i = 0, j = 0, cnt = 0;
		while (j < sz1 or j - i > sz2) {
			if (j - i <= sz2) {
				int y = s[j] - 'a';
				if (A[y] > 0) {
					if (B[y] < A[y]) {
						++cnt;
					}
					++B[y];
				}
				++j;
			}
			else {
				int x = s[i] - 'a';
				if (A[x] > 0) {
					if (B[x] == A[x]) {
						--cnt;
					}
					--B[x];
				}
				++i;
			}
			if (cnt == sz2 and j - i == sz2) {
				result.push_back(i);
			}
		}
		return result;
	}
};