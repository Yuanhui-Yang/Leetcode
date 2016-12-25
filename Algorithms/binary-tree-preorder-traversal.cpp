// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/
#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <iterator>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// BEGIN: http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		while (root) {
			if (!root->left) {
				result.push_back(root->val);
				root = root->right;
				continue;
			}
			TreeNode *predecessor = root->left;
			while (predecessor->right && predecessor->right != root) predecessor = predecessor->right;
			if (!predecessor->right) {
				result.push_back(root->val);
				predecessor->right = root;
				root = root->left;
				continue;
			}
			predecessor->right = NULL;
			root = root->right;
		}
		return result;
	}
};
// END: http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html

// BEGIN: http://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/
// class Solution {
// public:
// 	vector<int> preorderTraversal(TreeNode* root) {
// 		if (!root) return {};
// 		vector<int> result;
// 		vector<TreeNode*> stack;
// 		stack.push_back(root);
// 		while (!stack.empty()) {
// 			TreeNode *stack_top = stack.back();
// 			stack.pop_back();
// 			result.push_back(stack_top->val);
// 			if (stack_top->right) stack.push_back(stack_top->right);
// 			if (stack_top->left) stack.push_back(stack_top->left);
// 		}
// 		return result;
// 	}
// };
// END: http://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/

// class Solution {
// public:
// 	vector<int> preorderTraversal(TreeNode* root) {
// 		vector<int> result;
// 		this->preorderTraversal(root, result);
// 		return result;
// 	}
// private:
// 	void preorderTraversal(TreeNode* root, vector<int>& result) {
// 		if (!root) return;
// 		result.push_back(root->val);
// 		this->preorderTraversal(root->left, result);
// 		this->preorderTraversal(root->right, result);
// 	}
// };

// class Solution {
// public:
// 	vector<int> preorderTraversal(TreeNode* root) {
// 		if (!root) return {};
// 		vector<int> result = {root->val};
// 		vector<int> leftSubtree = this->preorderTraversal(root->left);
// 		vector<int> rightSubtree = this->preorderTraversal(root->right);
// 		result.insert(end(result), begin(leftSubtree), end(leftSubtree));
// 		result.insert(end(result), begin(rightSubtree), end(rightSubtree));
// 		return result;
// 	}
// };

int main(void) {
	Solution solution;
	TreeNode *root = NULL;
	root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	vector<int> result;
	result = solution.preorderTraversal(root);
	assert(vector<int>({1, 2, 3}) == result);
	cout << "\nPassed All\n";
	return 0;
}