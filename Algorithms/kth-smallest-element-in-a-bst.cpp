230. Kth Smallest Element in a BST
https://leetcode.com/problems/kth-smallest-element-in-a-bst/

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        root = clone(root);
        while (root and k > 0) {
            if (root->left) {
                TreeNode * pred = root->left;
                while (pred->right and pred->right != root) {
                    pred = pred->right;
                }
                if (pred->right == root) {
                    --k;
                    result = root->val;
                    root = root->right;
                    pred->right = NULL;
                }
                else {
                    pred->right = root;
                    root = root->left;
                }
            }
            else {
                --k;
                result = root->val;
                root = root->right;
            }
        }
        return result;
    }
private:
    TreeNode * clone(TreeNode * root) {
        TreeNode * result = NULL;
        if (root) {
            result = new TreeNode(root->val);
            result->left = clone(root->left);
            result->right = clone(root->right);
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    
    TreeNode * root = NULL;
    int k, result;
    
    root = new TreeNode(2);
    root->left = new TreeNode(1);
    k = 1;
    result = solution.kthSmallest(root, k);
    cout << result << '\n';
    
  
    return 0;
}