// 536. Construct Binary Tree from String
// https://leetcode.com/problems/construct-binary-tree-from-string/

/*
You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

Example:
Input: "4(2(3)(1))(6(5))"
Output: return the tree root node representing the following tree:

       4
     /   \
    2     6
   / \   / 
  3   1 5   
Note:
There will only be '(', ')', '-' and '0' ~ '9' in the input string.
An empty tree is represented by "" instead of "()".
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void gc(TreeNode* t) {
	if (t) {
		gc(t->left);
		gc(t->right);
		delete t;
	}
}

bool isSameTree(TreeNode *p, TreeNode *q) {
	if (!p and !q) {
		return true;
	}
	if (!p and q) {
		return false;
	}
	if (p and !q) {
		return false;
	}
	if (p->val != q->val) {
		return false;
	}
	return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
}

class Solution {
public:
	TreeNode* str2tree(string s) {
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
		root->left = str2tree(s.substr(i, j - i - 1));
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
		root->right = str2tree(s.substr(j, i - j - 1));
		return root;
	}
};

int main(void) {
	Solution solution;
	string s;
	TreeNode *result, *answer;

	s = "4(2(3)(1))(6(5))";
	answer = new TreeNode(4);
	answer->left = new TreeNode(2);
	answer->right = new TreeNode(6);
	answer->left->left = new TreeNode(3);
	answer->left->right = new TreeNode(1);
	answer->right->left = new TreeNode(5);
	result = solution.str2tree(s);
	assert(isSameTree(result, answer));

	cout << "\nPassed All\n";
	return 0;
}