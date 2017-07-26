// 366. Find Leaves of Binary Tree
// https://leetcode.com/problems/find-leaves-of-binary-tree/

/*
Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

Example:
Given binary tree 
		  1
		 / \
		2   3
	   / \     
	  4   5    
Returns [4, 5, 3], [2], [1].

Explanation:
1. Removing the leaves [4, 5, 3] would result in this tree:

		  1
		 / 
		2          
2. Now removing the leaf [2] would result in this tree:

		  1          
3. Now removing the leaf [1] would result in the empty tree:

		  []         
Returns [4, 5, 3], [2], [1].
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
	vector<vector<int>> findLeaves(TreeNode* root) {
		vector<vector<int>> result;
		if (!root) {
			return result;
		}
		for (vector<int> v = f(NULL, root); !v.empty(); v = f(NULL, root)) {
			result.push_back(v);
		}
		return result;
	}
private:
	vector<int> f(TreeNode * parent, TreeNode * & current) {
		vector<int> result;
		if (!current) {
			return result;
		}
		if (!current->left and !current->right) {
			result.push_back(current->val);
			if (parent and parent->left == current) {
				parent->left = NULL;
			}
			if (parent and parent->right == current) {
				parent->right = NULL;
			}
			current = NULL;
			return result;
		}
		vector<int> a = f(current, current->left), b = f(current, current->right);
		result.insert(end(result), begin(a), end(a));
		result.insert(end(result), begin(b), end(b));
		return result;
	}
};