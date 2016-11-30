// 222. Count Complete Tree Nodes
// https://leetcode.com/problems/count-complete-tree-nodes/
#include <iostream>
#include <cassert>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int countNodes(TreeNode* root) {
		if (!root) return 0;
		if (!root->left) return 1;
		if (!root->right) return 2;
		int h1 = 0;
		for (TreeNode *it = root; it; it = it->left) h1++;
		int h2 = 0;
		for (TreeNode *it = root; it; it = it->right) h2++;
		if (h1 == h2) return ((1 << h1) - 1);
		return countNodes(root->left) + countNodes(root->right) + 1;
	}
};
int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(0);
	root->left = new TreeNode(1);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	assert(5 == solution.countNodes(root));
	cout << "\nPassed All\n";
	return 0;
}