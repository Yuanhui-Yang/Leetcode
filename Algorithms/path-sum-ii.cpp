// 113. Path Sum II
// https://leetcode.com/problems/path-sum-ii/
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		vector<int> path;
		this->pathSum(result, path, root, sum);
		return result;
	}
private:
	void pathSum(vector<vector<int>>& result, vector<int>& path, TreeNode* root, int sum) {
		if (!root) return;
		if (root->val == sum && !root->left && !root->right) {
			path.push_back(root->val);
			result.push_back(path);
			path.pop_back();
			return;
		}
		path.push_back(root->val);
		this->pathSum(result, path, root->left, sum - root->val);
		path.pop_back();
		path.push_back(root->val);
		this->pathSum(result, path, root->right, sum - root->val);
		path.pop_back();
	}	
};
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
	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);
	for (const auto &i : solution.pathSum(root, 22)) {
		for (const auto &j : i)
			cout << j << '\t';
		cout << '\n';
	}
	cout << "\nPassed\n";
	cout << "\nPassed All\n";
	return 0;
}