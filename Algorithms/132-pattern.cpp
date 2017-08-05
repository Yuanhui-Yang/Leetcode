// 456. 132 Pattern
// https://leetcode.com/problems/132-pattern/

/*
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

Note: n will be less than 15,000.

Example 1:
Input: [1, 2, 3, 4]

Output: False

Explanation: There is no 132 pattern in the sequence.
Example 2:
Input: [3, 1, 4, 2]

Output: True

Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:
Input: [-1, 3, 2, 0]

Output: True

Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
*/

class Solution {
public:
	bool find132pattern(vector<int> & nums) {
		int sz = nums.size();
		if (sz < 3) {
			return false;
		}
		stack<int> stk;
		vector<int> A(sz);
		for (int i = 0; i < sz; ++i) {
			if (i == 0) {
			 A[i] = nums[i];
			}
			else {
				A[i] = min(A[i - 1], nums[i]);
			}
		}
		for (int i = sz - 1; i >= 0; --i) {
			if (nums[i] == A[i]) {
				continue;
			}
			if (stk.empty()) {
				stk.push(nums[i]);
				continue;
			}
			while (!stk.empty() and stk.top() <= A[i]) {
				stk.pop();
			}
			if (!stk.empty() and stk.top() < nums[i]) {
				return true;
			}
			stk.push(nums[i]);
		}
		return false;
	}
};