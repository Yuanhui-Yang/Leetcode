// 235. Lowest Common Ancestor of a Binary Search Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root) return NULL;
		if (!p) return q;
		if (!q) return p;
		if (p == q) return p;
		if (p->val > q->val) return this->lowestCommonAncestor(root, q, p);
		if (p->val <= root->val && root->val <= q->val) return root;
		if (p->val < root->val && q->val < root->val) return this->lowestCommonAncestor(root->left, p, q);
		if (p->val > root->val && q->val > root->val) return this->lowestCommonAncestor(root->right, p, q);
		return NULL;
	}
};
int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(6);
	root->left = new TreeNode(2);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(4);
	root->left->right->left = new TreeNode(3);
	root->left->right->right = new TreeNode(5);
	root->right->left = new TreeNode(7);
	root->right->right = new TreeNode(9);
	cout << solution.lowestCommonAncestor(root, root->left, root->right) << "\tPassed\n";
	cout << solution.lowestCommonAncestor(root, root->left, root->left->right) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}