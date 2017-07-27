// 515. Find Largest Value in Each Tree Row
// https://leetcode.com/problems/find-largest-value-in-each-tree-row/

/*
You need to find the largest value in each row of a binary tree.

Example:
Input: 

		  1
		 / \
		3   2
	   / \   \  
	  5   3   9 

Output: [1, 3, 9]
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
		if (!root) {
			return result;
		}
		for (list<TreeNode*> curr({root}), next; !curr.empty(); curr = next, next.clear()) {
			int maxVal = curr.front()->val;
			for (const auto & i : curr) {
				if (maxVal < i->val) {
					maxVal = i->val;
				}
				if (i->left) {
					next.push_back(i->left);
				}
				if (i->right) {
					next.push_back(i->right);
				}
			}
			result.push_back(maxVal);
		}
		return result;
	}
};