404. Sum of Left Leaves
https://leetcode.com/problems/sum-of-left-leaves/

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode * left, * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int result = 0;
        stack<TreeNode*> stk;
        while (!stk.empty() or root) {
            if (root) {
                stk.push(root);
                root = root->left;
            }
            else {
                TreeNode * top = stk.top();
                stk.pop();
                root = top->right;
                if (f1(top)) {
                    result += top->left->val;
                }
            }
        }
        return result;
    }
private:
    bool f1(TreeNode * node) {
        return node and node->left and !node->left->left and !node->left->right;
    }
};

int main(void) {
    Solution solution;
    TreeNode * root;
    int result;

    root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    result = solution.sumOfLeftLeaves(root);
    cout << result << '\n';

    return 0;
}
