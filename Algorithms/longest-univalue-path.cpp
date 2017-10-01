// 687. Longest Univalue Path
// https://leetcode.com/problems/longest-univalue-path/

/*
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode * left, * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int longestUnivaluePath(TreeNode* root) {
		return f(root)[0];
	}
private:
	array<int, 2> f(TreeNode * node) {
		array<int, 2> result;
		result.fill(0);
		if (!node) {
			return result;
		}
		array<int, 2> left = f(node->left), right = f(node->right);
		if (node->left and node->left->val == node->val) {
			result[1] = max(result[1], 1 + left[1]);
		}
		if (node->right and node->right->val == node->val) {
			result[1] = max(result[1], 1 + right[1]);
		}
		if (node->left and node->left->val == node->val and node->right and node->right->val == node->val) {
			result[0] = max(result[0], 2 + left[1] + right[1]);
		}
		result[0] = max(result[0], result[1]);
		result[0] = max(result[0], left[0]);
		result[0] = max(result[0], right[0]);
		return result;
	}
};

int main(void) {
	Solution solution;
	TreeNode * root = NULL;
	int result;
	
	root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(1);
	root->right->right = new TreeNode(5);
	result = solution.longestUnivaluePath(root);
	cout << result << '\n';

	root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(4);
	root->right->right = new TreeNode(5);
	result = solution.longestUnivaluePath(root);
	cout << result << '\n';

	return 0;
}