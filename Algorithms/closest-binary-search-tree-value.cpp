// 270. Closest Binary Search Tree Value
// https://leetcode.com/problems/closest-binary-search-tree-value/

/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
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
	int closestValue(TreeNode* root, double target) {
		if (!root) {
			return INT_MIN;
		}
		int result = root->val;
		while (root) {
			if (abs(root->val - target) < abs(result - target)) {
				result = root->val;
			}
			if (root->val == target) {
				return result;
			}
			if (root->val < target) {
				root = root->right;
			}
			else {
			root = root->left;
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	TreeNode *root;
	int answer, result;
	double target;

	root = new TreeNode(0);
	root->left = new TreeNode(1);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	target = 2.1;
	answer = 2;
	result = solution.closestValue(root, target);
	gc(root);
	assert(answer == result);

	root = new TreeNode(1);
	root->right = new TreeNode(2);
	target = 3.428571;
	answer = 2;
	result = solution.closestValue(root, target);
	gc(root);
	assert(answer == result);

	root = new TreeNode(8);
	root->left = new TreeNode(1);
	target = 6.0;
	answer = 8;
	result = solution.closestValue(root, target);
	gc(root);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}