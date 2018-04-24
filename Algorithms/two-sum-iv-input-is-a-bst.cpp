653. Two Sum IV - Input is a BST
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode * left, * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums = f1(root);
        int sz = nums.size(), i = 0, j = sz - 1;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == k) {
                return true;
            }
            else if (sum < k) {
                ++i;
            }
            else {
                --j;
            }
        }
        return false;
    }
private:
    vector<int> f1(TreeNode * root) {
        vector<int> result;
        stack<TreeNode *> stk;
        while (!stk.empty() or root) {
            if (root) {
                stk.push(root);
                root = root->left;
            }
            else {
                TreeNode * top = stk.top();
                stk.pop();
                result.push_back(top->val);
                root = top->right;
            }
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    TreeNode * root;
    int k;
    bool result;

    root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(4);
    k = 9;
    result = solution.findTarget(root, k);
    cout << boolalpha << result << '\n';

    root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(4);
    k = 28;
    result = solution.findTarget(root, k);
    cout << boolalpha << result << '\n';

    return 0;
}
