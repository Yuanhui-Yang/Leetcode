// 423. Reconstruct Original Digits from English
// https://leetcode.com/problems/reconstruct-original-digits-from-english/

/*
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"
*/

class Solution {
public:
	string originalDigits(string s) {
		array<int, 26> A;
		A.fill(0);
		for (const auto & i : s) {
			int id = i - 'a';
			++A[id];
		}
		array<int, 10> B;
		B.fill(0);
		B[0] = A['z' - 'a'];
		B[2] = A['w' - 'a'];
		B[4] = A['u' - 'a'];
		B[6] = A['x' - 'a'];
		B[8] = A['g' - 'a'];
		B[7] = A['s' - 'a'] - B[6];
		B[5] = A['v' - 'a'] - B[7];
		B[3] = A['h' - 'a'] - B[8];
		B[9] = A['i' - 'a'] - B[5] - B[6] - B[8];
		B[1] = A['o' - 'a'] - B[0] - B[2] - B[4];
		string result;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < B[i]; ++j) {
				result.push_back('0' + i);
			}
		}
		return result;
	}
};