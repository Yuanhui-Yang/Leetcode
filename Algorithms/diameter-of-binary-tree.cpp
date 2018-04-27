543. Diameter of Binary Tree
https://leetcode.com/problems/diameter-of-binary-tree/

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

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
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 1;
        f1(root, result);
        return result - 1;
    }
private:
    int f1(TreeNode * node, int & result) {
        if (!node) {
            return 0;
        }
        int left = f1(node->left, result), right = f1(node->right, result), length = 1 + left + right;
        result = max(result, length);
        return max(left, right) + 1;
    }
};

int main(void) {
    Solution solution;
    TreeNode * root = new TreeNode(1);
    int result;

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    result = solution.diameterOfBinaryTree(root);
    cout << result << '\n';

    return 0;
}
