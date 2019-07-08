1110. Delete Nodes And Return Forest
https://leetcode.com/problems/delete-nodes-and-return-forest/

Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest.  You may return the result in any order.

 

Example 1:



Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
 

Constraints:

The number of nodes in the given tree is at most 1000.
Each node has a distinct value between 1 and 1000.
to_delete.length <= 1000
to_delete contains distinct values between 1 and 1000.

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        sort(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;
        f1(root, NULL, result, to_delete);
        return result;
    }
private:
    void f1(TreeNode* root, TreeNode* parent, vector<TreeNode*> & result, vector<int>& to_delete)
    {
        if (root)
        {
            int val = root->val;
            TreeNode * left = root->left, * right = root->right;
            if (binary_search(to_delete.begin(), to_delete.end(), val))
            {
                if (parent)
                {
                    if (parent->left == root)
                    {
                        parent->left = NULL;
                    }
                    if (parent->right == root)
                    {
                        parent->right = NULL;
                    }
                }
                root->left = NULL;
                root->right = NULL;
                if (left)
                {
                    f1(left, NULL, result, to_delete);
                }
                if (right)
                {
                    f1(right, NULL, result, to_delete);
                }
            }
            else
            {
                if (!parent)
                {
                    result.push_back(root);
                }
                if (left)
                {
                    f1(left, root, result, to_delete);
                }
                if (right)
                {
                    f1(right, root, result, to_delete);
                }
            }
        }
    }
};