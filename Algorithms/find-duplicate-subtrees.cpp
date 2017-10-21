// 652. Find Duplicate Subtrees
// https://leetcode.com/problems/find-duplicate-subtrees/

/*
Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1: 
		1
	   / \
	  2   3
	 /   / \
	4   2   4
	   /
	  4
The following are two duplicate subtrees:
	  2
	 /
	4
and
	4
Therefore, you need to return above trees' root in the form of a list.
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode * left, * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		if (!root) {
			return {};
		}
		unordered_map<string, int> A;
		stack<TreeNode*> stk;
		vector<TreeNode*> result;
		string s;
		while (!stk.empty() or root) {
			if (root) {
				s = f1(root);
				stk.push(root);
				if (A.count(s) and A[s] == 1) {
					result.push_back(root);
				}
				++A[s];
				root = root->left;
			}
			else {
				root = stk.top()->right;
				stk.pop();
			}
		}
		return result;
	}
private:
	string f1(TreeNode * root) {
		return !root ? "#" : to_string(root->val) + "?" + f1(root->left) + ":" + f1(root->right);
	}
};

void f1(TreeNode * root) {
	if (root) {
		f1(root->left);
		cout << root->val << '\t';
		f1(root->right);
	}
	cout << '\n';
}

int main(void) {
	Solution solution;
	TreeNode * root = NULL;
	vector<TreeNode*> result;
	
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->left = new TreeNode(2);
	root->right->right = new TreeNode(4);
	root->right->left->left = new TreeNode(4);
	result = solution.findDuplicateSubtrees(root);
	for (const auto & i : result) {
		f1(i);
	}
	
	return 0;
}