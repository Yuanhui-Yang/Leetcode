// 696. Count Binary Substrings
// https://leetcode.com/problems/count-binary-substrings/

/*
Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".

Notice that some of these substrings repeat and are counted the number of times they occur.

Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:
Input: "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
Note:

s.length will be between 1 and 50,000.
s will only consist of "0" or "1" characters.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int countBinarySubstrings(string s) {
		int result = 0, sz = s.size(), i, prev = 0, curr = 0;
		for (i = 0; i < sz; ++i) {
			curr = 1;
			while (i + 1 < sz and s[i + 1] == s[i]) {
				++i;
				++curr;
			}
			result += min(prev, curr);
			prev = curr;
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	string s;
	int result;
	
	s = "00110011";
	result = solution.countBinarySubstrings(s);
	cout << result << '\n';

	s = "10101";
	result = solution.countBinarySubstrings(s);
	cout << result << '\n';

	return 0;
}