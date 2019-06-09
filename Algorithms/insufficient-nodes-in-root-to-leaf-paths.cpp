1084. Insufficient Nodes in Root to Leaf Paths
https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/

Given the root of a binary tree, consider all root to leaf paths: paths from the root to any leaf.  (A leaf is a node with no children.)

A node is insufficient if every such root to leaf path intersecting this node has sum strictly less than limit.

Delete all insufficient nodes simultaneously, and return the root of the resulting binary tree.

 

Example 1:


Input: root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1

Output: [1,2,3,4,null,null,7,8,9,null,14]
Example 2:


Input: root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22

Output: [5,4,8,11,null,17,4,7,null,null,null,5]
 

Note:

The given tree will have between 1 and 5000 nodes.
-10^5 <= node.val <= 10^5
-10^9 <= limit <= 10^9

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        TreeNode dummy(0);
        dummy.left = root;
        f1(&dummy, limit, 0);
        return dummy.left;
    }
private:
    TreeNode * f1(TreeNode* node, int limit, int sum)
    {
        sum += node->val;
        TreeNode * left = node->left, * right = node->right;
        if (!left and !right)
        {
            return sum < limit ? NULL : node;
        }
        if (left)
        {
            node->left = left = f1(node->left, limit, sum);
        }
        if (right)
        {
            node->right = right = f1(node->right, limit, sum);
        }
        return (!left and !right) ? NULL : node;
    }
};