// 404. Sum of Left Leaves
// https://leetcode.com/problems/sum-of-left-leaves/

/*
Find the sum of all left leaves in a given binary tree.

Example:

	3
   / \
  9  20
	/  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
	int sumOfLeftLeaves(TreeNode* root) {
		return f(root, NULL);
	}
private:
	int f(TreeNode * node, TreeNode* parent) {
		if (!node) {
			return 0;
		}
		if (!node->left and !node->right) {
			return parent and parent->left == node ? node->val : 0;
		}
		return f(node->left, node) + f(node->right, node);
	}
};