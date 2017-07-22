// 543. Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/

/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
		  1
		 / \
		2   3
	   / \     
	  4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };    int diameterOfBinaryTree(TreeNode* root) {

	}
 */
class Solution {
public:
	int diameterOfBinaryTree(TreeNode* root) {
		return max(0, f(root)[0] - 1);
	}
private:
	array<int, 2> f(TreeNode* node) {
		array<int, 2> result;
		if (!node) {
			result[0] = 0;
			result[1] = 0;
			return result;
		}
		array<int, 2> left = f(node->left), right = f(node->right);
		result[0] = 1 + left[1] + right[1];
		result[0] = max(result[0], left[0]);
		result[0] = max(result[0], right[0]);
		result[1] = 1 + max(left[1], right[1]);
		return result;
	}
};