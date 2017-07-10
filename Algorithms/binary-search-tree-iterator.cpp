// 173. Binary Search Tree Iterator
// https://leetcode.com/problems/binary-search-tree-iterator/

/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		node = root;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return node;
	}

	/** @return the next smallest number */
	int next() {
		int result;
		while (node) {
			if (!node->left) {
				result = node->val;
				node = node->right;
				break;
			}
			else {
				TreeNode * pred = node->left;
				while (pred->right and pred->right != node) {
					pred = pred->right;
				}
				if (!pred->right) {
					pred->right = node;
					node = node->left;
				}
				else {
					result = node->val;
					pred->right = NULL;
					node = node->right;
					break;
				}
			}
		}
		return result;
	}
private:
	TreeNode * node;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */