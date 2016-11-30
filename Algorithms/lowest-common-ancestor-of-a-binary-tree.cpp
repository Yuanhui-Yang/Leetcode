// 236. Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
#include <iostream>
#include <cassert>
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// BEGIN: https://discuss.leetcode.com/topic/20063/accepted-24ms-dfs-c-solution-only-3-lines
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || root == p || root == q) return root;
		if (!p) return q;
		if (!q) return p;
		if (p == q) return p;
		TreeNode *left = this->lowestCommonAncestor(root->left, p, q);
		TreeNode *right = this->lowestCommonAncestor(root->right, p, q);
		return left && right ? root : left ? left : right;
	}
};
// END: https://discuss.leetcode.com/topic/20063/accepted-24ms-dfs-c-solution-only-3-lines
int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);
	assert(root == solution.lowestCommonAncestor(root, root->left, root->right));
	assert(root->left == solution.lowestCommonAncestor(root, root->left, root->left->right->right));
	cout << "\nPassed All\n";
	return 0;
}