// 230. Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ? k ? BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
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
	int kthSmallest(TreeNode* root, int k) {
		int result;
		stack<TreeNode*> s;
		while (k > 0 and (root or !s.empty())) {
			if (root) {
				s.push(root);
				root = root->left;
			}
			else {
				TreeNode * node = s.top();
				s.pop();
				result = node->val;
				--k;
				root = node->right;
			}
		}
		return result;
	}
};

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
	int kthSmallest(TreeNode* root, int k) {
		int result = 0;
		while (root and k > 0) {
			if (!root->left) {
				result = root->val;
				root = root->right;
				--k;
			}
			else {
				TreeNode * pred = root->left;
				while (pred->right and pred->right != root) {
					pred = pred->right;
				}
				if (!pred->right) {
					pred->right = root;
					root = root->left;
				}
				else {
					result = root->val;
					pred->right = NULL;
					root = root->right;
					--k;
				}
			}
		}
		return result;
	}
};