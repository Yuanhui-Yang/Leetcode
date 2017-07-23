// 538. Convert BST to Greater Tree
// https://leetcode.com/problems/convert-bst-to-greater-tree/

/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
			  5
			/   \
		   2     13

Output: The root of a Greater Tree like this:
			 18
			/   \
		  20     13
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
	TreeNode* convertBST(TreeNode* root) {
		TreeNode * node = root;
		int sum = 0;
		while (node) {
			if (!node->right) {
				node->val += sum;
				sum = node->val;
				node = node->left;
			}
			else {
				TreeNode * pred = node->right;
				while (pred->left and pred->left != node) {
					pred = pred->left;
				}
				if (pred->left == node) {
					pred->left = NULL;
					node->val += sum;
					sum = node->val;
					node = node->left;
				}
				else {
					pred->left = node;
					node = node->right;
				}
			}
		}
		return root;
	}
};