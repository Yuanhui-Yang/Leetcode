// 124. Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/

/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
	int maxPathSum(TreeNode* root) {
		return f(root).second;
	}
private:
	pair<int, int> f(TreeNode* root) {
		if (!root) {
			return {INT_MIN, INT_MIN};
		}
		pair<int, int> a = f(root->left), b = f(root->right);
		int x = max(0, a.first), y = max(0, b.first);
		int l = root->val + max(x, y), r = max(root->val + x + y, max(a.second, b.second));
		return {l, r};
	}
};