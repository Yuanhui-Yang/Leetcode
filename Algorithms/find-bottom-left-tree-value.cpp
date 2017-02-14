// 513. Find Bottom Left Tree Value
// https://leetcode.com/problems/find-bottom-left-tree-value/
#include <iostream>
#include <cassert>
#include <vector>
#include <list>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int findBottomLeftValue(TreeNode* root) {
		int result = 0;
		list<TreeNode*> queue;
		queue.push_back(root);
		while (!queue.empty()) {
			result = queue.front()->val;
			list<TreeNode*> queue_tmp(begin(queue), end(queue));
			queue.clear();
			for (const auto &i : queue_tmp) {
				if (i->left) {
					queue.push_back(i->left);
				}
				if (i->right) {
					queue.push_back(i->right);
				}
			}
		}
		return result;
	}
};
int main(void) {
	Solution solution;
	TreeNode *root = NULL;
	int result = 0;
	int answer = 0;

	root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	answer = 1;
	result = solution.findBottomLeftValue(root);
	assert(answer == result);

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(6);
	root->right->left->left = new TreeNode(7);
	answer = 7;
	result = solution.findBottomLeftValue(root);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}