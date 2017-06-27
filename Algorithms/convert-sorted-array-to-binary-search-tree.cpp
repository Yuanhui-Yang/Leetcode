// 108. Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return f(nums, 0, nums.size());
	}
private:
	TreeNode *f(vector<int>& nums, int i, int j) {
		if (i >= j) {
			return NULL;
		}
		int mid = i + (j - i) / 2;
		TreeNode *root = new TreeNode(nums[mid]);
		TreeNode *l = f(nums, i, mid), *r = f(nums, mid + 1, j);
		root->left = l;
		root->right = r;
		return root;
	}
};