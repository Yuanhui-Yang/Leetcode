// 101. Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

	1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
	1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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
	bool isSymmetric(TreeNode* root) {
		return f(root, root);
	}
private:
	bool f(TreeNode * p, TreeNode * q) {
		if (!p and !q) {
			return true;
		}
		if (!p or !q) {
			return false;
		}
		return p->val == q->val and f(p->left, q->right) and f(p->right, q->left);
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
	bool isSymmetric(TreeNode* root) {
		queue<TreeNode*> curr;
		curr.push(root);
		curr.push(root);
		while (!curr.empty()) {
			TreeNode * a = curr.front();
			curr.pop();
			TreeNode * b = curr.front();
			curr.pop();
			if (!a and !b) {
				continue;
			}
			if (!a or !b) {
				return false;
			}
			if (a->val != b->val) {
				return false;
			}
			curr.push(a->left);
			curr.push(b->right);
			curr.push(a->right);
			curr.push(b->left);
		}
		return true;
	}
};