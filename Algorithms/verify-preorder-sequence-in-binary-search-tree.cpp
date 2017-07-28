// 255. Verify Preorder Sequence in Binary Search Tree
// https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/

/*
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Follow up:
Could you do it using only constant space complexity?
*/

class Solution {
public:
	bool verifyPreorder(vector<int>& preorder) {
		int lower = INT_MIN, sz = preorder.size();
		for (int i = 0, j = -1; i < sz; ++i) {
			if (preorder[i] < lower) {
				return false;
			}
			while (j >= 0 and preorder[j] < preorder[i]) {
				lower = preorder[j];
				--j;
			}
			preorder[++j] = preorder[i];
		}
		return true;
	}
};

class Solution {
public:
	bool verifyPreorder(vector<int>& preorder) {
		stack<int> s;
		int lower = INT_MIN;
		for (int sz = preorder.size(), i = 0; i < sz; ++i) {
			if (preorder[i] < lower) {
				return false;
			}
			while (!s.empty() and s.top() < preorder[i]) {
				lower = s.top();
				s.pop();
			}
			s.push(preorder[i]);
		}
		return true;
	}
};