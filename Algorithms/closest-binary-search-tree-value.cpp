// 270. Closest Binary Search Tree Value
// https://leetcode.com/problems/closest-binary-search-tree-value/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>
#include <cassert>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// BEGIN: https://discuss.leetcode.com/topic/22590/4-7-lines-recursive-iterative-ruby-c-java-python
class Solution {
public:
	int closestValue(TreeNode* root, double target) {
		if (!root) return 0;
		double minDiff = numeric_limits<double>::max();
		int	result = 0;
		while (root) {
			double diff = fabs((double)root->val - target);
			if (diff <= 0.5) return root->val;
			if (diff < minDiff) {
				minDiff = diff;
				result = root->val;
			}
			if ((double)root->val > target) root = root->left;
			else root = root->right;
		}
		return result;
	}
};
// END: https://discuss.leetcode.com/topic/22590/4-7-lines-recursive-iterative-ruby-c-java-python
int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(0);
	root->left = new TreeNode(1);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	assert(2 == solution.closestValue(root, 2.1));
	cout << "\nPassed All\n";
	return 0;
}