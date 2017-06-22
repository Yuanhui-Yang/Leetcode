// 106. Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return dfs(inorder, postorder, 0, inorder.size(), 0, postorder.size());
	}
private:
	TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int x1, int y1, int x2, int y2) {
		if (x1 >= y1 or x2 >= y2) {
			return NULL;
		}
		if (x1 + 1 == y1 and x2 + 1 == y2) {
			return new TreeNode(inorder[x1]);
		}
		int val = postorder[y2 - 1], i = x1;
			while (i < y1 and inorder[i] != val) {
			++i;
		}
		int l = i - x1, r = y1 - i - 1;
		TreeNode *root = new TreeNode(val);
		root->left = dfs(inorder, postorder, x1, x1 + l, x2, x2 + l);
		root->right = dfs(inorder, postorder, y1 - r, y1, y2 - 1 - r, y2 - 1);
		return root;
	}
};

int main(void) {
	Solution solution;
	vector<int> inorder, postorder;
	TreeNode *answer, *result;

	inorder = {2, 1};
	postorder = {2, 1};
	answer = new TreeNode(1);
	answer->left = new TreeNode(2);
	result = solution.buildTree(inorder, postorder);
	assert(isSameTree(answer, result));
	gc(answer);
	gc(result);

	cout << "\nPassed All\n";
	return 0;
}