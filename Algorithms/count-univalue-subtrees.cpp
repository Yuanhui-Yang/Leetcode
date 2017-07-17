// 250. Count Univalue Subtrees
// https://leetcode.com/problems/count-univalue-subtrees/

/*
Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
			  5
			 / \
			1   5
		   / \   \
		  5   5   5
return 4.
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
	int countUnivalSubtrees(TreeNode* root) {
		return f(root)[1];
	}
private:
	array<int, 2> f(TreeNode * node) {
		if (!node) {
			return {1, 0};
		}
		array<int, 2> left = f(node->left), right = f(node->right);
		if (!node->left and !node->right) {
			return {1, 1};
		}
		if (node->left and !node->right) {
			if (left[0] and node->val == node->left->val) {
				++left[1];
			}
			else {
				left[0] = 0;
			}
			return left;
		}
		if (!node->left and node->right) {
			if (right[0] and node->val == node->right->val) {
				++right[1];
			}
			else {
				right[0] = 0;
			}
			return right;
		}
		if (left[0] and right[0] and node->val == node->left->val and node->val == node->right->val) {
			return {1, left[1] + 1 + right[1]};
		}
		return {0, left[1] + right[1]};
	}
};