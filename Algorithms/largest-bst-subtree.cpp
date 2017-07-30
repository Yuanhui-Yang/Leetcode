// 333. Largest BST Subtree
// https://leetcode.com/problems/largest-bst-subtree/

/*
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:
	10
	/ \
   5  15
  / \   \ 
 1   8   7
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.
Follow up:
Can you figure out ways to solve it with O(n) time complexity?
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
	int largestBSTSubtree(TreeNode* root) {
		return f(root)[0];
	}
private:
	array<int, 4> f(TreeNode * node) { // largest number, valid, min val, max val
		if (!node) {
			return {0, 0, 0, 0};
		}
		if (!node->left and !node->right) {
			return {1, 1, node->val, node->val};
		}
		array<int, 4> left = f(node->left), right = f(node->right);
		if (node->left and !node->right) {
			if (left[1] and left[3] < node->val) {
				return {left[0] + 1, 1, left[2], node->val};
			}
			return {left[0], 0, 0, 0};
		}
		if (!node->left and node->right) {
			if (right[1] and node->val < right[2]) {
				return {right[0] + 1, 1, node->val, right[3]};
			}
			return {right[0], 0, 0, 0};
		}
		if (left[1] and right[1] and left[3] < node->val and node->val < right[2]) {
			return {left[0] + right[0] + 1, 1, left[2], right[3]};
		}
		return {max(left[0], right[0]), 0, 0, 0};
	}
};