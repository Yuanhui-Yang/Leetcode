// 450. Delete Node in a BST
// https://leetcode.com/problems/delete-node-in-a-bst/

/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

	5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

	5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

	5
   / \
  2   6
   \   \
	4   7
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
	TreeNode* deleteNode(TreeNode* root, int key) {
		TreeNode * dummy = new TreeNode(-1);
		dummy->left = root;
		TreeNode * prev = dummy, * curr = root;
		while (curr and curr->val != key) {
			prev = curr;
			if (curr->val < key) {
				curr = curr->right;
			}
			else {
				curr = curr->left;
			}
		}
		if (curr) {
			if (curr->right) {
				TreeNode * left = curr->left, * right = curr->right, * leftmost = min_element(right);
				if (prev->left == curr) {
					prev->left = right;
					leftmost->left = left;
				}
				else {
					prev->right = right;
					leftmost->left = left;
				}
			}
			else {
				if (prev->left == curr) {
					prev->left = curr->left;
				}
				else {
					prev->right = curr->left;
				}
			}
		}
		return dummy->left;
	}
private:
	TreeNode * min_element(TreeNode * node) {
		while (node and node->left) {
			node = node->left;
		}
		return node;
	}
};