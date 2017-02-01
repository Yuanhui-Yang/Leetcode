// 501. Find Mode in Binary Search Tree
// https://leetcode.com/problems/find-mode-in-binary-search-tree/
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <unordered_map>
#include <iterator>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<int> findMode(TreeNode* root) {
		if (!root) {
			return {};
		}
		unordered_map<int, int> OPT;
		inorderTraversal(root, OPT);
		map<int, vector<int>> treeMap;
		for (const auto &i : OPT) {
			treeMap[i.second].push_back(i.first);
		}
		return prev(end(treeMap))->second;
	}
private:
	void inorderTraversal(TreeNode* root, unordered_map<int, int>& OPT) {
		if (root) {
			inorderTraversal(root->left, OPT);
			OPT[root->val]++;
			inorderTraversal(root->right, OPT);
		}
	}
};
int main(void) {
	Solution solution;
	TreeNode *root = NULL;
	vector<int> result;

	result = solution.findMode(root);
	assert(vector<int>({}) == result);	

	root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(2);
	result = solution.findMode(root);
	assert(vector<int>({2}) == result);

	cout << "\nPassed All\n";
	return 0;
}