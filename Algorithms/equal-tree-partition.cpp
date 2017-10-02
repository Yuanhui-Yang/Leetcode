// 663. Equal Tree Partition
// https://leetcode.com/problems/equal-tree-partition/

/*
Given a binary tree with n nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.

Example 1:
Input:     
    5
   / \
  10 10
    /  \
   2   3

Output: True
Explanation: 
    5
   / 
  10
      
Sum: 15

   10
  /  \
 2    3

Sum: 15
Example 2:
Input:     
    1
   / \
  2  10
    /  \
   2   20

Output: False
Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.
Note:
The range of tree node value is in the range of [-100000, 100000].
1 <= n <= 10000
*/

#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
     int val;
    TreeNode * left, * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void gc(TreeNode * & node) {
    if (node) {
        gc(node->left);
        gc(node->right);
        delete node;
        node = NULL;
    }
}

class Solution {
public:
    bool checkEqualTree(TreeNode * root) {
        if (!root) {
            return false;
        }
        unordered_map<TreeNode*, int> A;
        int sum = f1(root, A), target = sum / 2;
        if (sum % 2) {
            return false;
        }
        return f2(root->left, A, target) or f2(root->right, A, target);
    }
private:
    int f1(TreeNode * node, unordered_map<TreeNode*, int> & A) {
        if (!node) {
            return 0;
        }
        if (A.count(node)) {
            return A[node];
        }
        return A[node] = f1(node->left, A) + node->val + f1(node->right, A);
    }
    bool f2(TreeNode * node, unordered_map<TreeNode*, int> & A, const int target) {
        if (!node) {
            return false;
        }
        if (f1(node, A) == target) {
            return true;
        }
        return f2(node->left, A, target) or f2(node->right, A, target);
    }
};

int main(void) {
    Solution solution;
    TreeNode * root = NULL;
    bool result;
    
    root = new TreeNode(5);
    root->left = new TreeNode(10);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(3);
    result = solution.checkEqualTree(root);
    gc(root);
    cout << boolalpha << result << '\n';

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(20);
    result = solution.checkEqualTree(root);
    gc(root);
    cout << boolalpha << result << '\n';

    return 0;
}