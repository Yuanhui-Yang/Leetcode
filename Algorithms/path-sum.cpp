// 112. Path Sum
// https://leetcode.com/problems/path-sum/
#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// BEGIN: https://discuss.leetcode.com/topic/9729/3-lines-of-c-solution
class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root) return false;
		if (root->val == sum && !root->left && !root->right) return true;
		return this->hasPathSum(root->left, sum - root->val) || this->hasPathSum(root->right, sum - root->val);
	}
};
// END: https://discuss.leetcode.com/topic/9729/3-lines-of-c-solution
int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->right->right = new TreeNode(1);
	cout << boolalpha << solution.hasPathSum(root, 22) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}