// 107. Binary Tree Level Order Traversal II
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		if (!root) {
			return {};
		}
		vector<vector<int>> result;
		list<TreeNode*> c = {root};
		while (!c.empty()) {
			list<TreeNode*> n;
			vector<int> v;
			for (const auto &i : c) {
				v.push_back(i->val);
				if (i->left) {
					n.push_back(i->left);
				}
				if (i->right) {
					n.push_back(i->right);
				}
			}
			result.push_back(v);
			c = n;
		}
		reverse(begin(result), end(result));
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<vector<int>> answer, result;
	string s;

	s = "3(9)(20(15)(7))";
	answer = {{15, 7}, {9, 20}, {3}};
	result = solution.levelOrderBottom(g(s));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}