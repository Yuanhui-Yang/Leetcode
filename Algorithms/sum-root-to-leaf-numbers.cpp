// 129. Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers/

/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
	int sumNumbers(TreeNode* root) {
		return f(root, 0);
	}
private:
	int f(TreeNode * node, int sum) {
		if (!node) {
			return sum;
		}
		if (!node->left and !node->right) {
			return sum * 10 + node->val;
		}
		if (!node->left and node->right) {
			return f(node->right, sum * 10 + node->val);
		}
		if (node->left and !node->right) {
			return f(node->left, sum * 10 + node->val);
		}
		return f(node->left, sum * 10 + node->val) + f(node->right, sum * 10 + node->val);
	}
};