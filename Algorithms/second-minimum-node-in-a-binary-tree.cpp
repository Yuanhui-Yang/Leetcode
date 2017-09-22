// 671. Second Minimum Node In a Binary Tree
// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

/*
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:
Input: 
	2
   / \
  2   5
	 / \
	5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:
Input: 
	2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
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
	int findSecondMinimumValue(TreeNode* root) {
		if (!root) {
			return -1;
		}
		queue<TreeNode*> curr;
		curr.push(root);
		int a = root->val, b = INT_MAX;
		while (!curr.empty()) {
			TreeNode * front = curr.front(), * left = front->left, * right = front->right;
			curr.pop();
			if (left and left->val == a) {
				curr.push(left);
			}
			else if (left and left->val < b) {
				b = left->val;
			}
			if (right and right->val == a) {
				curr.push(right);
			}
			else if (right and right->val < b) {
				b = right->val;
			}
		}
		return b == INT_MAX ? -1 : b;
	}
};