// 889. Construct Binary Tree from Preorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

// Return any binary tree that matches the given preorder and postorder traversals.

// Values in the traversals pre and post are distinct positive integers.

 

// Example 1:

// Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
// Output: [1,2,3,4,5,6,7]
 

// Note:

// 1 <= pre.length == post.length <= 30
// pre[] and post[] are both permutations of 1, 2, ..., pre.length.
// It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int sz = pre.size();
        if (sz == 0) {
            return NULL;
        }
        reverse(post.begin(), post.end());
        return f1(pre, 0, sz, post, 0, sz);
    }
private:
    TreeNode * f1(vector<int>& pre, int a1, int b1, vector<int>& post, int a2, int b2) {
        if (a1 >= b1) {
            return NULL;
        }
        TreeNode * root = new TreeNode(pre[a1]);
        ++a1;
        ++a2;
        if (a1 >= b1) {
            return root;
        }
        int left = pre[a1];
        int right = post[a2];
        if (left == right) {
            root->left = f1(pre, a1, b1, post, a2, b2);
            return root;
        }
        int c1 = a1;
        int c2 = a2;
        while (c1 < b1 and pre[c1] != right) {
            ++c1;
        }
        while (c2 < b2 and post[c2] != left) {
            ++c2;
        }
        root->left = f1(pre, a1, c1, post, c2, b2);
        root->right = f1(pre, c1, b1, post, a2, c2);
        return root;
    }
};

void inorder(TreeNode * root) {
    if (root) {
        inorder(root->left);
        cout << root->val << '\t';
        inorder(root->right);
    }
}

int main(void) {
    Solution solution;
    vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    vector<int> post = {4, 5, 2, 6, 7, 3, 1};
    TreeNode * result = solution.constructFromPrePost(pre, post);
    inorder(result);
    return 0;
}