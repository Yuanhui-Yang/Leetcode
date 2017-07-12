// 222. Count Complete Tree Nodes
// https://leetcode.com/problems/count-complete-tree-nodes/

/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int countNodes(TreeNode* root) {
		if (!root) {
			return 0;
		}
		TreeNode * n1 = root, * n2 = root;
		int l1 = 0, l2 = 0;
		while (n1) {
			++l1;
			n1 = n1->left;
		}
		while (n2) {
			++l2;
			n2 = n2->right;
		}
		if (l1 == l2) {
			return (1 << l1) - 1;
		}
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
};