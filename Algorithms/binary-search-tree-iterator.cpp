173. Binary Search Tree Iterator
https://leetcode.com/problems/binary-search-tree-iterator/

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        this->node = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return node;
    }

    /** @return the next smallest number */
    int next() {
        int result = 0;
        bool flag = true;
        while (node and flag) {
            if (node->left) {
                TreeNode * pred = node->left;
                while (pred->right and pred->right != node) {
                    pred = pred->right;
                }
                if (pred->right) {
                    result = node->val;
                    pred->right = NULL;
                    node = node->right;
                    flag = false;
                }
                else {
                    pred->right = node;
                    node = node->left;
                }
            }
            else {
                result = node->val;
                node = node->right;
                flag = false;
            }
        }
        return result;
    }
private:
    TreeNode * node;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode * top = stk.top();
        int result = top->val;
        stk.pop();
        top = top->right;
        while (top) {
            stk.push(top);
            top = top->left;
        }
        return result;
    }
private:
    stack<TreeNode*> stk;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
