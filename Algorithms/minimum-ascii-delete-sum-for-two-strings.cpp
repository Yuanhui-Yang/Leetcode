// 712. Minimum ASCII Delete Sum for Two Strings
// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

/*
Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
Example 2:
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
Note:

0 < s1.length, s2.length <= 1000.
All elements of each string will have an ASCII value in [97, 122].
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minimumDeleteSum(string s1, string s2) {
		int sz1 = s1.size(), sz2 = s2.size(), i, j, sum;
		vector<vector<int>> A(sz1 + 1, vector<int>(sz2 + 1, 0));
		sum = 0;
		for (i = 1; i <= sz1; ++i) {
			sum += s1[i - 1];
			A[i][0] = sum;
		}
		sum = 0;
		for (j = 1; j <= sz2; ++j) {
			sum += s2[j - 1];
			A[0][j] = sum;
		}
		for (i = 1; i <= sz1; ++i) {
			for (j = 1; j <= sz2; ++j) {
				if (s1[i - 1] == s2[j - 1]) {
					A[i][j] = A[i - 1][j - 1];
				}
				else {
					A[i][j] = min(A[i - 1][j] + s1[i - 1], A[i][j - 1] + s2[j - 1]);
				}
			}
		}
		return A[sz1][sz2];
	}
};

int main(void) {
	Solution solution;
	string s1, s2;
	int result;
	
	s1 = "sea";
	s2 = "eat";
	result = solution.minimumDeleteSum(s1, s2);
	cout << result << '\n';
	
	s1 = "delete";
	s2 = "leet";
	result = solution.minimumDeleteSum(s1, s2);
	cout << result << '\n';   
	
	return 0;
}