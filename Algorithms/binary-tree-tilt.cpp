// 563. Binary Tree Tilt
// https://leetcode.com/problems/binary-tree-tilt/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void gc(TreeNode* root) {
	if (root) {
		gc(root->left);
		gc(root->right);
		delete root;
	}
}

class Solution {
public:
	int findTilt(TreeNode* root) {
		return dfs(root).second;
	}
private:
	pair<int, int> dfs(TreeNode* root) {
		if (!root) {
			return {0, 0};
		}
		pair<int, int> l = dfs(root->left), r = dfs(root->right);
		return {root->val + l.first + r.first, abs(l.first - r.first) + l.second + r.second};
	}
};

int main(void) {
	Solution solution;
	TreeNode* root;
	int answer, result;

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	answer = 1;
	result = solution.findTilt(root);
	gc(root);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}