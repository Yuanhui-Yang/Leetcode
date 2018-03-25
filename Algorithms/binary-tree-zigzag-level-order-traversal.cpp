103. Binary Tree Zigzag Level Order Traversal
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

#include <iostream>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool l2r = true;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> line(sz);
            for (int i = 0; i < sz; ++i) {
                int j = i;
                if (!l2r) {
                    j = sz - 1 - i;
                }
                TreeNode * front = q.front();
                TreeNode * left = front->left;
                TreeNode * right = front->right;
                q.pop();
                line[j] = front->val;
                if (left) {
                    q.push(left);
                }
                if (right) {
                    q.push(right);
                }
            }
            l2r = !l2r;
            result.push_back(line);
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    TreeNode * root = NULL;
    vector<vector<int>> result;

    root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    result = solution.zigzagLevelOrder(root);
    for (const auto & i : result) {
        for (const auto & j : i) {
            cout << j << '\t';
        }
        cout << '\n';
    }
    
    return 0;
}