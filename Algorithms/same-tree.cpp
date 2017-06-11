// 100. Same Tree
// https://leetcode.com/problems/same-tree/

/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p and !q) {
			return p == q;
		}
		return p->val == q->val and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
	}
};

int main(void) {
	Solution solution;
	TreeNode *p, *q;
	bool result, answer;

	p = new TreeNode(1);
	p->right = new TreeNode(1);
	q = new TreeNode(1);
	q->right = new TreeNode(1);
	answer = true;
	result = solution.isSameTree(p, q);
	gc(p);
	gc(q);
	assert(answer == result);

	cout << "\nPassed all\n";
	return 0;
}