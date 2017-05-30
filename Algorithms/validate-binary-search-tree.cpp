// 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/

/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void gc(TreeNode* root) {
	if (root) {
		gc(root->left);
		gc(root->right);
		delete root;
	}
}

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		stack<TreeNode*> stk;
		TreeNode *c = root, *p = NULL;
		while (!stk.empty() or c) {
			if (c) {
				stk.push(c);
				c = c->left;
			}
			else {
				TreeNode *t = stk.top();
				stk.pop();
				if (p and p->val >= t->val) {
					return false;
				}
				p = t;
				c = t->right;
			}
		}
		return true;
	}
};

int main(void) {
	Solution solution;
	TreeNode *root = NULL;
	bool result, answer;

	root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(15);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(20);
	answer = false;
	result = solution.isValidBST(root);
	gc(root);
	assert(answer == result);

	root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	answer = true;
	result = solution.isValidBST(root);
	gc(root);
	assert(answer == result);

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	answer = false;
	result = solution.isValidBST(root);
	gc(root);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}