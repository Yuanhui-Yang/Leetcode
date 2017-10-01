// 545. Boundary of Binary Tree
// https://leetcode.com/problems/boundary-of-binary-tree/

/*
Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.

Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.

The right-most node is also defined by the same way with left and right exchanged.

Example 1
Input:
  1
   \
	2
   / \
  3   4

Ouput:
[1, 3, 4, 2]

Explanation:
The root doesn't have left subtree, so the root itself is left boundary.
The leaves are node 3 and 4.
The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
So order them in anti-clockwise without duplicates and we have [1,3,4,2].
Example 2
Input:
	____1_____
   /          \
  2            3
 / \          / 
4   5        6   
   / \      / \
  7   8    9  10  
	   
Ouput:
[1,2,4,7,8,9,10,6,3]

Explanation:
The left boundary are node 1,2,4. (4 is the left-most node according to definition)
The leaves are node 4,7,8,9,10.
The right boundary are node 1,3,6,10. (10 is the right-most node).
So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode * left, * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void gc(TreeNode * & root) {
	if (root) {
		gc(root->left);
		gc(root->right);
		delete root;
		root = NULL;
	}
}

class Solution {
public:
	vector<int> boundaryOfBinaryTree(TreeNode* root) {
		vector<int> result;
		if (!root) {
			return result;
		}
		result.push_back(root->val);
		f1(root->left, result);
		f2(root->left, result);
		f2(root->right, result);
		f3(root->right, result);
		return result;
	}
	
private:
	void f1(TreeNode * root, vector<int> & result) {
		if (!root) {
			return;
		}
		while (root->left or root->right) {
			result.push_back(root->val);
			if (root->left) {
				root = root->left;
			}
			else {
				root = root->right;
			}
		}
	}
	void f2(TreeNode * root, vector<int> & result) {
		if (!root) {
			return;
		}
		if (!root->left and !root->right) {
			result.push_back(root->val);
			return;
		}
		f2(root->left, result);
		f2(root->right, result);
	}
	void f3(TreeNode * root, vector<int> & result) {
		if (!root) {
			return;
		}
		int sz = result.size();
		while (root->left or root->right) {
			result.push_back(root->val);
			if (root->right) {
				root = root->right;
			}
			else {
				root = root->left;
			}
		}
		reverse(next(begin(result), sz), end(result));
	}
};

int main(void) {
	Solution solution;
	TreeNode * root = NULL;
	vector<int> result;

	root = new TreeNode(1);
	result = solution.boundaryOfBinaryTree(root);
	gc(root);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';
	
	root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(4);
	result = solution.boundaryOfBinaryTree(root);
	gc(root);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(8);
	root->right->left->left = new TreeNode(9);
	root->right->left->right = new TreeNode(10);
	result = solution.boundaryOfBinaryTree(root);
	gc(root);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';

	return 0;
}

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode * left, * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void gc(TreeNode * & root) {
	if (root) {
		gc(root->left);
		gc(root->right);
		delete root;
		root = NULL;
	}
}

class Solution {
public:
	vector<int> boundaryOfBinaryTree(TreeNode* root) {
		vector<int> result, A, B, C;
		if (!root) {
			return result;
		}
		result.push_back(root->val);
		f1(root->left, A);
		f2(root->left, B);
		f2(root->right, B);
		f3(root->right, C);
		result.insert(end(result), begin(A), end(A));
		result.insert(end(result), begin(B), end(B));
		result.insert(end(result), begin(C), end(C));
		return result;
	}
	
private:
	void f1(TreeNode * root, vector<int> & A) {
		if (!root) {
			return;
		}
		while (root->left or root->right) {
			A.push_back(root->val);
			if (root->left) {
				root = root->left;
			}
			else {
				root = root->right;
			}
		}
	}
	void f2(TreeNode * root, vector<int> & B) {
		if (!root) {
			return;
		}
		if (!root->left and !root->right) {
			B.push_back(root->val);
			return;
		}
		f2(root->left, B);
		f2(root->right, B);
	}
	void f3(TreeNode * root, vector<int> & C) {
		if (!root) {
			return;
		}
		while (root->left or root->right) {
			C.push_back(root->val);
			if (root->right) {
				root = root->right;
			}
			else {
				root = root->left;
			}
		}
		reverse(begin(C), end(C));
	}
};

int main(void) {
	Solution solution;
	TreeNode * root = NULL;
	vector<int> result;

	root = new TreeNode(1);
	result = solution.boundaryOfBinaryTree(root);
	gc(root);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';
	
	root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(4);
	result = solution.boundaryOfBinaryTree(root);
	gc(root);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(8);
	root->right->left->left = new TreeNode(9);
	root->right->left->right = new TreeNode(10);
	result = solution.boundaryOfBinaryTree(root);
	gc(root);
	for (const auto & i : result) {
		cout << i << '\t';
	}
	cout << '\n';

	return 0;
}