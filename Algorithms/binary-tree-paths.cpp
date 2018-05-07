257. Binary Tree Paths
https://leetcode.com/problems/binary-tree-paths/

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode * left, * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        f1(result, "", root);
        return result;
    }
private:
    void f1(vector<string> & result, string path, TreeNode* root) {
        if (!root) {
            return;
        }
        if (path.empty()) {
            path.append(to_string(root->val));
        }
        else {
            path.append("->" + to_string(root->val));
        }
        if (!root->left and !root->right) {
            result.push_back(path);
            return;
        }
        f1(result, path, root->left);
        f1(result, path, root->right);
    }
};

int main(void) {
    Solution solution;
    TreeNode * root;
    vector<string> result;

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    result = solution.binaryTreePaths(root);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    return 0;
}
