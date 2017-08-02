// 556. Next Greater Element III
// https://leetcode.com/problems/next-greater-element-iii/

/*
Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:
Input: 12
Output: 21
Example 2:
Input: 21
Output: -1
*/

class Solution {
public:
	int nextGreaterElement(int n) {
		string s = to_string(n);
		bool flag = next_permutation(begin(s), end(s));
		long long result = stoll(s);
		return flag and result < INT_MAX ? result : -1;
	}
};