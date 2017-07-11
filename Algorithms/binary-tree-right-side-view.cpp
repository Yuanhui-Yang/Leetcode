// 199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/

/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
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
	vector<int> rightSideView(TreeNode* root) {
		if (!root) {
			return {};
		}
		vector<int> result;
		list<TreeNode*> current = {root};
		while (!current.empty()) {
			result.push_back(current.back()->val);
			list<TreeNode*> next;
			for (const auto & i : current) {
				if (i->left) {
					next.push_back(i->left);
				}
				if (i->right) {
					next.push_back(i->right);
				}
			}
			current = next;
		}
		return result;
	}
};

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
	vector<int> rightSideView(TreeNode* root) {
		if (!root) {
			return {};
		}
		int maxDepth = -1;
		vector<int> result;
		f(result, maxDepth, 0, root);
		return result;
	}
private:
	void f(vector<int> & result, int & maxDepth, int depth, TreeNode* node) {
		if (!node) {
			return;
		}
		if (depth > maxDepth) {
			maxDepth = max(maxDepth, depth);
			result.push_back(node->val);
		}
		f(result, maxDepth, depth + 1, node->right);
		f(result, maxDepth, depth + 1, node->left);
	}
};