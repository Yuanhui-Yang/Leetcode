// 314. Binary Tree Vertical Order Traversal
// https://leetcode.com/problems/binary-tree-vertical-order-traversal/
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
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
	vector<vector<int>> verticalOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (!root) return result;
		unordered_map<TreeNode*, TreeNode*> Child2Parent;
		unordered_map<TreeNode*, int> Node2Offset;
		map<int, vector<int>> Offset2Nodes;
		queue<TreeNode*> q;
		q.push(root);
		Node2Offset[root] = 0;
		Offset2Nodes[0].push_back(root->val);
		while (!q.empty()) {
			TreeNode *front = q.front();
			if (front->left) {
				Child2Parent[front->left] = front;
				Node2Offset[front->left] = Node2Offset[front] - 1;
				Offset2Nodes[Node2Offset[front->left]].push_back(front->left->val);
				q.push(front->left);
			}
			if (front->right) {
				Child2Parent[front->right] = front;
				Node2Offset[front->right] = Node2Offset[front] + 1;
				Offset2Nodes[Node2Offset[front->right]].push_back(front->right->val);
				q.push(front->right);
			}
			q.pop();
		}
		for (const auto &i : Offset2Nodes) result.push_back(i.second);
		return result;
	}
};
int main(void) {
	Solution solution;

	TreeNode *root = NULL;
	for (const auto &i : solution.verticalOrder(root)) {
		for (const auto &j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	cout << "\nPassed\n";

	root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->left = new TreeNode(7);
	for (const auto &i : solution.verticalOrder(root)) {
		for (const auto &j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	cout << "\nPassed\n";

	root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(0);
	root->right->left = new TreeNode(1);
	root->right->right = new TreeNode(7);
	for (const auto &i : solution.verticalOrder(root)) {
		for (const auto &j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	cout << "\nPassed\n";

	root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(0);
	root->right->left = new TreeNode(1);
	root->right->right = new TreeNode(7);
	root->left->right->right = new TreeNode(2);
	root->right->left->left = new TreeNode(5);
	for (const auto &i : solution.verticalOrder(root)) {
		for (const auto &j : i) {
			cout << j << '\t';
		}
		cout << '\n';
	}
	cout << "\nPassed\n";	
	cout << "\nPassed All\n";
	return 0;
}