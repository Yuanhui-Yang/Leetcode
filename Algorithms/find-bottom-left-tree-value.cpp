// 513. Find Bottom Left Tree Value
// https://leetcode.com/problems/find-bottom-left-tree-value/

/*
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

	2
   / \
  1   3

Output:
1
Example 2: 
Input:

		1
	   / \
	  2   3
	 /   / \
	4   5   6
	   /
	  7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
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
	int findBottomLeftValue(TreeNode* root) {
		list<TreeNode*> curr = {root};
		while (!curr.empty()) {
			list<TreeNode*> next;
			for (const auto & i : curr) {
				if (i->left) {
					next.push_back(i->left);
				}
				if (i->right) {
					next.push_back(i->right);
				}
			}
			if (next.empty()) {
				return curr.front()->val;
			}
			else {
				curr = next;
			}
		}
		return -1;
	}
};