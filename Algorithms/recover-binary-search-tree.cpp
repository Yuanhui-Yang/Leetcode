// 99. Recover Binary Search Tree
// https://leetcode.com/problems/recover-binary-search-tree/

/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string f(TreeNode* root) {
	if (!root) {
		return "";
	}
	if (!root->left and !root->right) {
		return to_string(root->val);
	}
	if (root->left and !root->right) {
		return to_string(root->val) + "(" + f(root->left) + ")";
	}
	return to_string(root->val) + "(" + f(root->left) + ")(" + f(root->right) + ")";
}

TreeNode* g(string s) {
	if (s.empty()) {
		return NULL;
	}
	int n = s.size(), i = 0;
	while (i < n and s[i] != '(') {
		++i;
	}
	TreeNode *root = new TreeNode(stoi(s.substr(0, i)));
	if (i >= n) {
		return root;
	}
	int j = ++i, k = 1;
	while (j < n and k > 0) {
		if (s[j] == '(') {
			++k;
		}
		else if (s[j] == ')') {
			--k;
		}
		++j;
	}
	root->left = g(s.substr(i, j - i - 1));
	if (j >= n) {
		return root;
	}
	i = ++j;
	k = 1;
	while (i < n and k > 0) {
		if (s[i] == '(') {
		++k;
	}
	else if (s[i] == ')') {
		--k;
	}
		++i;
	}
	root->right = g(s.substr(j, i - j - 1));
	return root;
}

class Solution {
public:
	void recoverTree(TreeNode* root) {
		TreeNode *prev = NULL, *a = NULL, *b = NULL;
		while (root) {
			if (!root->left) {
				if (prev and prev->val > root->val) {
					if (!a) {
						a = prev;
						b = root;
					}
					else {
						b = root;
					}
				}
				prev = root;
				root = root->right;
			}
			else {
				TreeNode *pred = root->left;
				while (pred->right and pred->right != root) {
					pred = pred->right;
				}
				if (!pred->right) {
					pred->right = root;
					root = root->left;
				}
				else {
					if (prev and prev->val > root->val) {
						if (!a) {
							a = prev;
							b = root;
						}
						else {
							b = root;
						}
					}
					pred->right = NULL;
					prev = root;
					root = root->right;
				}
			}
		}
		if (a and b) {
			swap(a->val, b->val);
		}
	}
};

int main(void) {
	Solution solution;
	TreeNode *root;
	string u, v;

	u = "0(1)";
	v = "1(0)";
	root = g(u);
	solution.recoverTree(root);
	u = f(root);
	assert(v == u);

	cout << "\nPassed All\n";
	return 0;
}