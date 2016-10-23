// 437. Path Sum III
// https://leetcode.com/problems/path-sum-iii/
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		if (!root) return 0;
		int result = 0;
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode *front = q.front();
			q.pop();
			this->helper(front, result, sum);
			if (front->left) q.push(front->left);
			if (front->right) q.push(front->right);
		}
		return result;
	}
private:
	void helper(TreeNode* root, int& result, int sum) {
		if (!root) return;
		if (root->val == sum) {
			result++;
		}
		this->helper(root->left, result, sum - root->val);
		this->helper(root->right, result, sum - root->val);
	}
};
int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(-3);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(2);
	root->left->left->left = new TreeNode(3);
	root->left->left->right = new TreeNode(-2);
	root->left->right->right = new TreeNode(1);
	root->right->right = new TreeNode(11);
	cout << solution.pathSum(root, 8) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}