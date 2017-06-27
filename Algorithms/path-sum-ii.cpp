// 113. Path Sum II
// https://leetcode.com/problems/path-sum-ii/

/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		vector<int> v;
		f(result, v, root, sum);
		return result;
	}
private:
	void f(vector<vector<int>>& result, vector<int>& v, TreeNode* root, int sum) {
		if (!root) {
			return;
		}
		if (!root->left and !root->right) {
			if (sum == root->val) {
				v.push_back(root->val);
				result.push_back(v);
				v.pop_back();
			}
			return;
		}
		v.push_back(root->val);
		f(result, v, root->left, sum - root->val);
		v.pop_back();
		v.push_back(root->val);
		f(result, v, root->right, sum - root->val);
		v.pop_back();
	}
};