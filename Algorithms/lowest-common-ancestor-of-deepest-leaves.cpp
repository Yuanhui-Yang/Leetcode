1123. Lowest Common Ancestor of Deepest Leaves
https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

Given a rooted binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0, and if the depth of a node is d, the depth of each of its children is d+1.
The lowest common ancestor of a set S of nodes is the node A with the largest depth such that every node in S is in the subtree with root A.
 

Example 1:

Input: root = [1,2,3]
Output: [1,2,3]
Explanation: 
The deepest leaves are the nodes with values 2 and 3.
The lowest common ancestor of these leaves is the node with value 1.
The answer returned is a TreeNode object (not an array) with serialization "[1,2,3]".
Example 2:

Input: root = [1,2,3,4]
Output: [4]
Example 3:

Input: root = [1,2,3,4,5]
Output: [2,4,5]
 

Constraints:

The given tree will have between 1 and 1000 nodes.
Each node of the tree will have a distinct value between 1 and 1000.

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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int max_depth = f1(root);
        unordered_set<TreeNode*> A;
        unordered_map<TreeNode*, unordered_set<TreeNode*>> B;
        f2(A, B, root, NULL, max_depth, 1);
        return f3(A, B, root);
    }
private:
    int f1(TreeNode* root)
    {
        return root ? 1 + max(f1(root->left), f1(root->right)) : 0;
    }
    void f2(unordered_set<TreeNode*> & A, unordered_map<TreeNode*, unordered_set<TreeNode*>> & B, TreeNode* root, TreeNode* parent, int max_depth, int depth)
    {
        if (root)
        {
            if (parent)
            {
                B[root].insert(parent);
            }
            if (depth == max_depth)
            {
                A.insert(root);
            }
            else
            {
                f2(A, B, root->left, root, max_depth, depth + 1);
                f2(A, B, root->right, root, max_depth, depth + 1); 
            }
        }
    }
    TreeNode * f3(unordered_set<TreeNode*> & A, unordered_map<TreeNode*, unordered_set<TreeNode*>> & B, TreeNode* root)
    {
        while (A.size() > 1)
        {
            unordered_set<TreeNode*> NA;
            for (auto from : A)
            {
                if (from == root)
                {
                    return root;
                }
                else if (B.count(from))
                {
                    for (auto to : B[from])
                    {
                        NA.insert(to);
                    }   
                }
            }
            swap(A, NA);
        }
        return *A.begin();
    }
};