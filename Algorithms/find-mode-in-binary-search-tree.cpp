// 501. Find Mode in Binary Search Tree
// https://leetcode.com/problems/find-mode-in-binary-search-tree/

/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
	\
	 2
	/
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
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
	vector<int> findMode(TreeNode* root) {
		vector<int> result;
		int maxCnt = 0, cnt = 0;
		TreeNode * prev = NULL;
		while (root) {
			if (!root->left) {
				if (prev == NULL or prev->val != root->val) {
					cnt = 1;
					prev = root;
				}
				else {
					++cnt;
				}
				if (maxCnt < cnt) {
					maxCnt = cnt;
					result.clear();
					result.push_back(root->val);
				}
				else if (maxCnt == cnt) {
					result.push_back(root->val);
				}
				root = root->right;
			}
			else {
				TreeNode * pred = root->left;
				while (pred->right and pred->right != root) {
					pred = pred->right;
				}
				if (pred->right == root) {
					if (prev == NULL or prev->val != root->val) {
						cnt = 1;
						prev = root;
					}
					else {
						++cnt;
					}
					if (maxCnt < cnt) {
						maxCnt = cnt;
						result.clear();
						result.push_back(root->val);
					}
					else if (maxCnt == cnt) {
						result.push_back(root->val);
					}
					pred->right = NULL;
					root = root->right;
				}
				else {
					pred->right = root;
					root = root->left;
				}
			}
		}
		return result;
	}
};