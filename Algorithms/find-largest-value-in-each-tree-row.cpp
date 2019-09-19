/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
 *
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (58.46%)
 * Likes:    562
 * Dislikes: 48
 * Total Accepted:    71.6K
 * Total Submissions: 122.4K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * You need to find the largest value in each row of a binary tree.
 * 
 * Example:
 * 
 * Input: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      / \   \  
 * ⁠     5   3   9 
 * 
 * Output: [1, 3, 9]
 * 
 * 
 * 
 */
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;
        if (root)
        {
            q.push(root);
            while (!q.empty())
            {
                int sz = q.size();
                int max_val = INT_MIN;
                while (sz-- > 0)
                {
                    root = q.front();
                    q.pop();
                    int val = root->val;
                    max_val = max(max_val, val);
                    TreeNode* left = root->left, *right = root->right;
                    if (left)
                    {
                        q.push(left);
                    }
                    if (right)
                    {
                        q.push(right);
                    }
                }
                result.push_back(max_val);
            }
        }
        return result;
    }
};