// 450. Delete Node in a BST
// https://leetcode.com/problems/delete-node-in-a-bst/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root) return NULL;
		if (root->val == key) {
			if (!root->left && !root->right) return NULL;
			if (!root->left) return root->right;
			if (!root->right) return root->left;
			TreeNode *it = root->right;
			while (it->left) it = it->left;
			it->left = root->left;
			return root->right;		
		}
		root->left = deleteNode(root->left, key);
		root->right = deleteNode(root->right, key);
		return root;
	}
};
void inorderTraversal(TreeNode *root) {
	if (root) {
		inorderTraversal(root->left);
		cout << root->val << '\t';
		inorderTraversal(root->right);
	}
}
int main(void) {
	Solution solution;
	TreeNode *root = NULL;
	root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->right->right = new TreeNode(7);
	TreeNode *result = solution.deleteNode(root, 3);
	inorderTraversal(result);
	cout << "\nPassed All\n";
	return 0;
}