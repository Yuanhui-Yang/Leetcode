// 530. Minimum Absolute Difference in BST
// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void gc(TreeNode* root) {
	if (root) {
		gc(root->left);
		gc(root->right);
		delete root;
	}
}

class Solution {
public:
	int getMinimumDifference(TreeNode* root) {
		int result = INT_MAX;
		TreeNode *p = NULL;
		stack<TreeNode*> s;
		while (!s.empty() or root) {
			if (root) {
				s.push(root);
				root = root->left;
			}
			else {
				TreeNode *t = s.top();
				s.pop();
				if (p) {
					result = min(result, t->val - p->val);
				}
				p = t;
				root = t->right;
			}
		}
		return result;
	}
};

// class Solution {
// public:
// 	int getMinimumDifference(TreeNode* root) {
// 		int result = INT_MAX;
// 		TreeNode *p = NULL;
// 		while (root) {
// 			if (!root->left) {
// 				if (p) {
// 					result = min(result, root->val - p->val);
// 				}
// 				p = root;
// 				root = root->right;
// 				continue;
// 			}
// 			TreeNode *pred = root->left;
// 			while (pred->right and pred->right != root) {
// 				pred = pred->right;
// 			}
// 			if (!pred->right) {
// 				pred->right = root;
// 				root = root->left;
// 				continue;
// 			}
// 			pred->right = NULL;
// 			if (p) {
// 				result = min(result, root->val - p->val);
// 			}
// 			p = root;
// 			root = root->right;
// 		}
// 		return result;
// 	}
// };

int main(void) {
	Solution solution;
	TreeNode *root;
	int answer, result;

	root = new TreeNode(1);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(2);
	answer = 1;
	result = solution.getMinimumDifference(root);
	gc(root);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}