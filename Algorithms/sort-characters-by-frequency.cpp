// 451. Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/

/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

class Solution {
public:
	string frequencySort(string s) {
		array<int, 256> A;
		A.fill(0);
		int maxVal = 0;
		for (const auto & i : s) {
			++A[i];
			maxVal = max(maxVal, A[i]);
		}
		vector<vector<char>> B(maxVal + 1);
		for (int i = 0; i < 256; ++i) {
			if (A[i] == 0) {
				continue;
			}
			B[A[i]].push_back(i);
		}
		string result;
		for (int i = maxVal; i >= 0; --i) {
			if (B[i].empty()) {
				continue;
			}
			for (const auto & j : B[i]) {
				string s(i, j);
				result.append(s);
			}
		}
		return result;
	}
};