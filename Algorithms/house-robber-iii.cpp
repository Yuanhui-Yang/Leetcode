// 337. House Robber III
// https://leetcode.com/problems/house-robber-iii/

/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
	 3
	/ \
   2   3
	\   \ 
	 3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
	 3
	/ \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
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
	int rob(TreeNode* root) {
		if (!root) {
			return 0;
		}
		array<int, 2> A = f(root);
		return max(A[0], A[1]);
	}
private:
	array<int, 2> f(TreeNode * node) {
		if (!node) {
			return {0, 0};
		}
		array<int, 2> L = f(node->left), R = f(node->right), result({0, 0});
		result[0] = node->val + L[1] + R[1];
		result[1] = max(max(L[0] + R[0], L[0] + R[1]), max(L[1] + R[0], L[1] + R[1]));
		return result;
	}
};