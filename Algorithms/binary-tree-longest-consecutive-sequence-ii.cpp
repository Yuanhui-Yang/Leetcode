// 549. Binary Tree Longest Consecutive Sequence II
// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/

/*
Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.

Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid. On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.

Example 1:
Input:
		1
	   / \
	  2   3
Output: 2
Explanation: The longest consecutive path is [1, 2] or [2, 1].
Example 2:
Input:
		2
	   / \
	  1   3
Output: 3
Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
Note: All the values of tree nodes are in the range of [-1e7, 1e7].
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int longestConsecutive(TreeNode* root) {
		return f(root)[0];
	}
private:
	array<int, 3> f(TreeNode * node) {
		array<int, 3> result;
		result.fill(0);
		if (!node) {
			return result;
		}
		result.fill(1);
		if (!node->left and !node->right) {
			return result;
		}
		array<int, 3> l = f(node->left), r = f(node->right);
		if (node->right and node->val - 1 == node->right->val) {
			result[1] = max(result[1], 1 + r[1]);
		}
		if (node->right and node->val + 1 == node->right->val) {
			result[2] = max(result[2], 1 + r[2]);
		}
		if (node->left and node->val - 1 == node->left->val) {
			result[1] = max(result[1], 1 + l[1]);
		}
		if (node->left and node->val + 1 == node->left->val) {
			result[2] = max(result[2], 1 + l[2]);
		}
		result[0] = max(result[0], max(l[0], r[0]));
		result[0] = max(result[0], max(l[1], r[1]));
		result[0] = max(result[0], max(result[1], result[2]));
		if (node->left and node->right and node->val + 1 == node->left->val and node->val - 1 == node->right->val) {
			result[0] = max(result[0], l[2] + 1 + r[1]);
		}
		if (node->left and node->right and node->val - 1 == node->left->val and node->val + 1 == node->right->val) {
			result[0] = max(result[0], l[1] + 1 + r[2]);
		}
		return result;
	}
};

void gc(TreeNode * node) {
	if (node) {
		gc(node->left);
		gc(node->right);
		delete node;
	}
}

int main(void) {
	Solution solution;
	TreeNode * root = NULL;

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	cout << solution.longestConsecutive(root) << '\n';
	gc(root);

	root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	cout << solution.longestConsecutive(root) << '\n';
	gc(root);

	root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->left->right = new TreeNode(2);
	cout << solution.longestConsecutive(root) << '\n';
	gc(root);

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	cout << solution.longestConsecutive(root) << '\n';
	gc(root);

	root = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->right->left->left = new TreeNode(1);
	cout << solution.longestConsecutive(root) << '\n';
	gc(root);
	
	return 0;
}