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
		stack<int> curr;
		int sz = preorder.size(), minVal = INT_MIN;
		for (int i = 0; i < sz; ++i) {
			int val = preorder[i];
			if (val < minVal) {
				return false;
			}
			while (!curr.empty() and curr.top() < val) {
				minVal = curr.top();
				curr.pop();
			}
			curr.push(val);
		}
		return true;
	}
};