// 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/

/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		return f(root) >= 0;
	}
private:
	int f(TreeNode* root) {
		if (!root) {
			return 0;
		}
		int l = f(root->left), r = f(root->right);
		if (l < 0 or r < 0 or abs(l - r) > 1) {
			return -1;
		}
		return 1 + max(l, r);
	}
};