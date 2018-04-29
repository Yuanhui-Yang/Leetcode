314. Binary Tree Vertical Order Traversal
https://leetcode.com/problems/binary-tree-vertical-order-traversal/

Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:

Given binary tree [3,9,20,null,null,15,7],
   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
Given binary tree [3,9,8,4,0,1,7],
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
return its vertical order traversal as:
[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2
return its vertical order traversal as:
[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

struct TreeNode {
    int val;
    TreeNode * left, * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        map<int, vector<int>> A = f1(root);
        return f2(A);
    }
private:
    map<int, vector<int>> f1(TreeNode* root) {
        map<int, vector<int>> result;
        queue<tuple<int, TreeNode*>> q;
        q.emplace(0, root);
        while (!q.empty()) {
            tuple<int, TreeNode*> front = q.front();
            q.pop();
            int offset = get<0>(front);
            root = get<1>(front);
            result[offset].push_back(root->val);
            TreeNode * left = root->left, * right = root->right;
            if (left) {
                q.emplace(offset - 1, left);
            }
            if (right) {
                q.emplace(offset + 1, right);
            }
        }
        return result;
    }
    vector<vector<int>> f2(map<int, vector<int>> & A) {
        vector<vector<int>> result;
        for (const auto & i : A) {
            result.push_back(i.second);
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    TreeNode * root;
    vector<vector<int>> result;

    root = NULL;
    result = solution.verticalOrder(root);
    for (const auto & i : result) {
        for (const auto & j : i) {
            cout << j << '\t';
        }
        cout << '\n';
    }

    root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    result = solution.verticalOrder(root);
    for (const auto & i : result) {
        for (const auto & j : i) {
            cout << j << '\t';
        }
        cout << '\n';
    }

    root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(0);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(7);
    result = solution.verticalOrder(root);
    for (const auto & i : result) {
        for (const auto & j : i) {
            cout << j << '\t';
        }
        cout << '\n';
    }

    root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(0);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(7);
    root->left->right->right = new TreeNode(2);
    root->right->left->left = new TreeNode(5);
    result = solution.verticalOrder(root);
    for (const auto & i : result) {
        for (const auto & j : i) {
            cout << j << '\t';
        }
        cout << '\n';
    }

    return 0;
}
