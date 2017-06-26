// 95. Unique Binary Search Trees II
// https://leetcode.com/problems/unique-binary-search-trees-ii/

/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
	vector<TreeNode*> generateTrees(int n) {
		if (n <= 0) {
			return {};
		}
		return f(1, n);
	}
private:
	vector<TreeNode*> f(int a, int b) {
		if (a > b) {
			return {NULL};
		}
		if (a == b) {
			TreeNode *root = new TreeNode(a);
			return {root};
		}
		vector<TreeNode*> result;
		for (int i = a; i <= b; ++i) {
			vector<TreeNode*> l = f(a, i - 1), r = f(i + 1, b);
			for (const auto &j : l) {
				for (const auto &k : r) {
					TreeNode *root = new TreeNode(i);
					root->left = j;
					root->right = k;
					result.push_back(root);
				}
			}
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	int n;
	vector<string> answer, result;

	n = 3;
	answer = {"1()(2()(3))", "1()(3(2))", "2(1)(3)", "3(1()(2))", "3(2(1))"};
	sort(begin(answer), end(answer));
	result.clear();
	for (const auto &i : solution.generateTrees(n)) {
		result.push_back(f(i));
	}
	sort(begin(result), end(result));
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}