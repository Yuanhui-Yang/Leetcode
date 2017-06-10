// 104. Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
	int maxDepth(TreeNode* root) {
		return !root ? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
};

int main(void) {
	Solution solution;
	TreeNode *root;
	int answer, result;

	root = NULL;
	answer = 0;
	result = solution.maxDepth(root);
	gc(root);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}