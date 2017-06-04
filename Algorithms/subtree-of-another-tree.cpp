// 572. Subtree of Another Tree
// https://leetcode.com/problems/subtree-of-another-tree/

/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
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
	bool isSubtree(TreeNode* s, TreeNode* t) {
		return isSameTree(s, t) or (s->left and isSubtree(s->left, t)) or (s->right and isSubtree(s->right, t));
	}
private:
	bool isSameTree(TreeNode* s, TreeNode* t) {
		if (!s or !t) {
			return s == t;
		}
		return s->val == t->val and isSameTree(s->left, t->left) and isSameTree(s->right, t->right);
	}
};

int main(void) {
	Solution solution;
	TreeNode *s, *t;
	bool answer, result;

	s = new TreeNode(3);
	s->left = new TreeNode(4);
	s->right = new TreeNode(5);
	s->left->left = new TreeNode(1);
	s->left->right = new TreeNode(2);
	t = new TreeNode(4);
	t->left = new TreeNode(1);
	t->right = new TreeNode(2);
	answer = true;
	result = solution.isSubtree(s, t);
	gc(s);
	gc(t);
	assert(answer == result);

	s = new TreeNode(3);
	s->left = new TreeNode(4);
	s->right = new TreeNode(5);
	s->left->left = new TreeNode(1);
	s->left->right = new TreeNode(2);
	s->left->right->left = new TreeNode(0);
	t = new TreeNode(4);
	t->left = new TreeNode(1);
	t->right = new TreeNode(2);
	answer = false;
	result = solution.isSubtree(s, t);
	gc(s);
	gc(t);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}