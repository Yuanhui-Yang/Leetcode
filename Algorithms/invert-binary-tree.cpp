// 226. Invert Binary Tree
// https://leetcode.com/problems/invert-binary-tree/

/*
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void gc(TreeNode*& root) {
	if (root) {
		gc(root->left);
		gc(root->right);
		delete root;
		root = NULL;
	}
}

bool isSameTree(TreeNode* p, TreeNode* q) {
	if (!p and !q) {
		return p == q;
	}
	return p->val == q->val and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
}

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root) {
			return NULL;
		}
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};

int main(void) {
	Solution solution;
	TreeNode *root, *answer, *result;

	root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);

	answer = new TreeNode(4);
	answer->left = new TreeNode(7);
	answer->right = new TreeNode(2);
	answer->left->left = new TreeNode(9);
	answer->left->right = new TreeNode(6);
	answer->right->left = new TreeNode(3);
	answer->right->right = new TreeNode(1);

	result = solution.invertTree(root);
	gc(answer);
	gc(result);
	assert(isSameTree(answer, result));

	cout << "\nPassed All\n";
	return 0;
}