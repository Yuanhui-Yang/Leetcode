687. Longest Univalue Path
https://leetcode.com/problems/longest-univalue-path/

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

#include <iostream>
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
        int result = 0;
        f1(result, root);
        return result;
    }
private:
    int f1(int & result, TreeNode * root) {
        if (!root) {
            return 0;
        }
        int x = f1(result, root->left);
        int y = f1(result, root->right);
        int a = (root->left && root->left->val == root->val) ? 1 + x : 0;
        int b = (root->right && root->right->val == root->val) ? 1 + y : 0;
        result = max(result, a + b);
        return max(a, b);
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