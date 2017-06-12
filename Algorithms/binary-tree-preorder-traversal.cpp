// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/

/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> result;
		while (!s.empty() or root) {
			if (root) {
				result.push_back(root->val);
				s.push(root);
				root = root->left;
			}
			else {
				TreeNode *t = s.top();
				s.pop();
				root = t->right;
			}
		}
		return result;
	}
};

// class Solution {
// public:
// 	vector<int> preorderTraversal(TreeNode* root) {
// 		vector<int> result;
// 		while (root) {
// 			if (!root->left) {
// 				result.push_back(root->val);
// 				root = root->right;
// 			}
// 			else {
// 				TreeNode *pred = root->left;
// 				while (pred->right and pred->right != root) {
// 					pred = pred->right;
// 				}
// 				if (!pred->right) {
// 					result.push_back(root->val);
// 					pred->right = root;
// 					root = root->left;
// 				}
// 				else {
// 					pred->right = NULL;
// 					root = root->right;
// 				}
// 			}
// 		}
// 		return result;
// 	}
// };

int main(void) {
	Solution solution;
	TreeNode *root;
	vector<int> result, answer;

	root = NULL;
	result = solution.preorderTraversal(root);
	gc(root);
	answer = {};
	assert(answer == result);

	root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	result = solution.preorderTraversal(root);
	gc(root);
	answer = {1, 2, 3};
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}